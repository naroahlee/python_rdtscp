#include <Python.h>
#include <stdint.h>

static inline uint64_t _rdtscp(void)
{
	unsigned long _hi, _lo;
	asm volatile("rdtscp" : "=a"(_lo), "=d"(_hi));
	uint64_t val = (((uint64_t)_hi) << 32 | ((uint64_t)_lo));
	return val;
}

/*  Wrapped RDTSCP function */
static PyObject* rdtscp(PyObject* self, PyObject* args)
{
    uint64_t res;
    res = _rdtscp();

    /*  construct the output from res, to python long */
    return Py_BuildValue("l", res);
}

/*  define functions in module */
static PyMethodDef rdtscpMethods[] =
{
     {"rdtscp", rdtscp, METH_VARARGS, "evaluate the cosine"},
     {NULL, NULL, 0, NULL}
};


/* module initialization */
/* Python version 2 */
PyMODINIT_FUNC
initrdtscp_module(void)
{
    (void) Py_InitModule("rdtscp_module", rdtscpMethods);
}

