#initmove
from ctypes import *

def main(dll_name, time, elapset_time):
    #print "init move main", time, elapset_time
	fnRotateY = CDLL(dll_name).rotateY
	fnRotateY.argtypes = (c_int, c_float)	
	fnRotateAxis = CDLL(dll_name).rotateAxis
	fnRotateAxis.argtypes = (c_int, c_float, POINTER(c_float))
	#
	fnRotateY(5, 0.3 * 6.28*elapset_time)
    

