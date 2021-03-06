//
//  factorial.c
//  
//
//  Created by Paulina Overaite on 2017-02-20.
//
//


#include "stdio.h"
#include <Python.h>

int factorial(int);

//int main()
//{
//    int number;
//    
//    printf("Please enter the number which factorial you want to get ");
//    scanf("%d", &number);
//    
//    printf("The answer is %d\n", factorial(number));
//}

int factorial(int n)
{
    if(n<0)
        printf("Incorrect input");
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
    
}

static PyObject * factorial_system(PyObject *self, PyObject *args)
{
    int n;
    int sts;
    if(!PyArg_ParseTuple(args, "i", &n))
        return NULL;
    sts = factorial(n);
    return Py_BuildValue("i", sts);
}

static PyMethodDef factorialMethods[]={
    {"factorial", factorial_system, METH_VARARGS, "Find factorial."},
    {NULL,NULL,0,NULL}
};

static struct PyModuleDef factorialmodule= {
    PyModuleDef_HEAD_INIT,
    "factorial",
    NULL,
    -1,
    factorialMethods
};

PyMODINIT_FUNC PyInit_factorial(void){
    return PyModule_Create(&factorialmodule);
}

static PyObject *unknownError;
initunknown(void){
        PyObject *m;
        spam Error = PyErr_NewException("unknown.error", NULL, NULL);
        Py_INCREF(unknownError);
	PyModule_AddObject(m, "error", spamError);
}

