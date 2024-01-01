// add.c
#include <Python.h>

// Function in C
int add_numbers(int a, int b) {
    return a + b;
}

// Python interface
static PyObject* add_numbers_py(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return PyLong_FromLong(add_numbers(a, b));
}

// Method table
static PyMethodDef addnums_methods[] = {
    {"add_numbers", add_numbers_py, METH_VARARGS, "Add two numbers."},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef addnums = {
    PyModuleDef_HEAD_INIT,
    "addnums", //This is module name
    NULL,
    -1,
    addnums_methods
};

// Module initialization
PyMODINIT_FUNC PyInit_addnums(void) {
    return PyModule_Create(&addnums);
}
