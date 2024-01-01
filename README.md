# addnums

This is a simple tutorial on how to write python extension in C through a process called "wrapping" or creating a Python extension module.
## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install python-config and apt for installing python3-dev.

```bash
pip install python-config
sudo apt-get install python3-dev
```

## Compiling the shared library

To compile this you will need the GNU C compiler Collection [gcc](https://gcc.gnu.org/)

```bash
sudo apt-get install build-essential gcc

gcc add.c  $(python3-config --includes) -shared -fPIC -o addnums.so

OR 

gcc -o addnums.so -shared -fPIC add.c -I/path/to/python/include -lpython3.x
```
## Usage

```python
import addnums # make sure you are in same directory as addnums.so
result = addnums.add_numbers(5, 4)
print(result)  # Output: 9
```

## Distributing the package

```plaintext
addnums/
├── addnums.so
├── add.c
├── add.py
└── setup.py

```
```python
from setuptools import setup, Extension

setup(
    name='addnums',
    version='1.0',
    ext_modules=[Extension('addnums', ['addnums.so'])],
    packages=['addnums'],
    license='GPL',
    long_description=open('README.md').read(),
)

```
```bash
python3 setup.py bdist_wheel

```
