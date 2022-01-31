# -*- coding: cp1251 -*-
# dll must be x64 if python 64 bit. 

from ctypes import *
import timeit
import os

import initmesh
import initmove

print("Hi")
#===========================================
def onCreate(i):
    print("onCreate " + str(i))
    return 0

def beforeCreate(i):
    dll_name = namePath()
    initmesh.main(dll_name)
    print("beforeCreate " + str(i))      
    return 0
	
def onReset(i):
    print("onReset " + str(i))
    return 0

def onMove(time, elapset_time):
    dll_name = namePath()
    initmove.main(dll_name, time, elapset_time)
    return 3

def onRender(time, elapset_time):
    #print("onRender ",time,elapset_time,int(1/elapset_time))
    return 2 + int(time + elapset_time)
    
def onLost(i):
    print("onLost " + str(i))
    return 0
	
def onDestroy(i):
    print("onDestroy " + str(i))
    return 0

#===========================================
def namePath():
    return u'./sln/x64/Debug/Vovk3d.dll'
    #return u'./Release/pyShadowMap.dll'

def run_callback():
    os.chdir('..')
    dll_name = namePath()
    print(dll_name)
    fncb  = CDLL(dll_name).fncallback
    fncb.restype = c_int
    #fncb.argtypes = (c_double, c_float )
    FUNC_INT_DOUBLE_FLOAT = CFUNCTYPE(c_int, c_double, c_float)
    FUNC_INT_INT = CFUNCTYPE(c_int, c_int)
    COnFn = FUNC_INT_DOUBLE_FLOAT(onRender) #convert pyton function to C function
    print(fncb(COnFn))

    fnOnCreate  = CDLL(dll_name).onCreateCb
    fnOnReset   = CDLL(dll_name).onResetCb
    fnOnMove    = CDLL(dll_name).onMoveCb
    fnOnRender  = CDLL(dll_name).onRenderCb
    fnOnLost    = CDLL(dll_name).onLostCb
    fnOnDestroy = CDLL(dll_name).onDestroyCb

    COnCreate = FUNC_INT_INT(onCreate)
    COnReset  = FUNC_INT_INT(onReset)
    COnMove   = FUNC_INT_DOUBLE_FLOAT(onMove)
    COnRender = FUNC_INT_DOUBLE_FLOAT(onRender) #convert pyton function to C function
    COnLost   = FUNC_INT_INT(onLost)
    COnDestroy= FUNC_INT_INT(onDestroy)

    fnOnCreate(COnCreate)
    fnOnReset(COnReset)
    print(fnOnMove(COnMove))
    print (fnOnRender(COnRender))
    fnOnLost(COnLost)
    fnOnDestroy(COnDestroy)

    CBeforeCreate = FUNC_INT_INT(beforeCreate) # need this variable
    CDLL(dll_name).beforeCreateCb(CBeforeCreate)
    
    #===========================================

    rundll = CDLL(dll_name).runApp
    rundll()
    
    COnLost()
    COnDestroy()
    
#'''

'''    
def user_array():
    intArray5 = c_int * 5
    ia = intArray5(1,2,3,4,5)
    print ia
    print ia[3]

def string_array():
    string = c_char * 50
    modelNameArray = string * 2
    mna = modelNameArray(string(*"12"), string(*"khgkhjj"))
    print mna[1][3]
    print len(mna[0])
    print ord(mna[0][9])

#main_callback()
#string_array()
'''
run_callback()
