#include <Python.h>
#include "levenshtein.h"

static PyObject *
py_levenshtein(PyObject *self, PyObject *args)
{
    const char *word1;
    const char *word2;
    int dist;

    if (!PyArg_ParseTuple(args, "ss", &word1, &word2))
        return NULL;
    dist = (int)levenshtein(word1, word2);
    return Py_BuildValue("i", dist);
}

static PyMethodDef levenshteinMethods[] = {
    {"distance",  py_levenshtein, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initlevenshtein(void)
{
    PyObject *m;
    m = Py_InitModule("levenshtein", levenshteinMethods);
    if (m == NULL)
        return;
}
