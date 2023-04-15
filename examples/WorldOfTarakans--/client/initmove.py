#initmove
from ctypes import CDLL, c_int, c_float, POINTER

def main(dll_name, time, elapset_time):
    #print "init move main", time, elapset_time
    fnRotateY = CDLL(dll_name).rotateY
    fnRotateY.argtypes = (c_int, c_float)    
    fnRotateAxis = CDLL(dll_name).rotateAxis
    fnRotateAxis.argtypes = (c_int, c_float, POINTER(c_float))
    #
    '''
    fnRotateY(1, D3DX_PI * fElapsedTime / 4.0f);
    fnRotateY(2, -D3DX_PI * fElapsedTime / 4.0f);
    v = ( 0.1f, 1.0f, -0.2f );
    fnRotateAxis(3, -D3DX_PI * fElapsedTime / 6.0f, v);
    fnRotateY(4, -D3DX_PI * fElapsedTime / 4.0f);
    fnRotateY(5, 0.3 * 6.28*elapset_time)
    '''

