# init mesh
from ctypes import *

def main(dll_name):
    ws50 = c_wchar * 50
    float16 = c_float * 16
    D3DXMATRIXA16 = float16
    fnAddMesh = CDLL(dll_name).addMesh
    fnAddMesh.restype = c_int
    fnAddMesh.argtypes= (POINTER(c_wchar), POINTER(c_float))
    #fnAddMesh(ws50(*u"UI\\arrow.x"),
    #          float16(5.5, 0.0, 0.0, 0.0, #// arrow1
    #                  0.0, 0.0, 5.5, 0.0, 
    #                  0.0, -9.0, 0.0, 0.0, 
    #                  5.0, 0.2, 5.0, 1.0))
    meshFile = [
    ws50(*u"room.x"),
    ws50(*u"airplane\\airplane 2.x"),
    ws50(*u"misc\\car.x"),
    ws50(*u"misc\\sphere.x"),
    #ws50(*u"UI\\arrow.x"),
    ws50(*u"UI\\arrow.x"),
    ws50(*u"UI\\arrow.x"),
    ws50(*u"UI\\arrow.x"),
    
    ws50(*u"UI\\arrow.x"),
    ws50(*u"UI\\arrow.x"),
    ws50(*u"UI\\arrow.x"),
    ws50(*u"UI\\arrow.x"),
    ws50(*u"ring.x"),
    ws50(*u"ring.x"),]

    mInitMatrWorld = [
    D3DXMATRIXA16(	3.5, 0.0, 0.0, 0.0, #//room
					0.0, 3.0, 0.0, 0.0, 
					0.0, 0.0, 3.5, 0.0, 
					0.0, 0.0, 0.0, 1.0 ),
    D3DXMATRIXA16(  0.43301, 0.25, 0.0, 0.0, #//airplane
					-0.25, 0.43301, 0.0, 0.0, 
					0.0, 0.0, 0.5, 0.0, 
					5.0, 1.33975, 0.0, 1.0 ),
    D3DXMATRIXA16(  0.8, 0.0, 0.0, 0.0, #// car
					0.0, 0.8, 0.0, 0.0, 
					0.0, 0.0, 0.8, 0.0, 
					-14.5, -7.1, 0.0,1.0 ),
    D3DXMATRIXA16(  2.0, 0.0, 0.0, 0.0, #// sphere
					0.0, 2.0, 0.0, 0.0, 
					0.0, 0.0, 2.0, 0.0, 
					0.0, -7.0, 0.0,1.0 ),
    #//D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, #// arrow1
				#//	0.0, 0.0, 5.5, 0.0, 
				#//	0.0, -9.0, 0.0, 0.0, 
				#//	5.0, 0.2, 5.0, 1.0 ),
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					5.0, 0.2, -5.0, 1.0 ),
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					-5.0, 0.2, 5.0, 1.0 ),
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					-5.0, 0.2, -5.0, 1.0 ),
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					14.0, 0.2, 14.0,1.0 ),
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					14.0, 0.2, -14.0, 1.0 ),
    #======
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					-14.0, 0.2, 14.0, 1.0 ),
    D3DXMATRIXA16( 5.5, 0.0, 0.0, 0.0, 
					0.0, 0.0, 5.5, 0.0, 
					0.0, -9.0, 0.0, 0.0, 
					-14.0, 0.2, -14.0, 1.0 ),
    D3DXMATRIXA16( 0.9, 0.0, 0.0, 0.0, 
					0.0, 0.9, 0.0, 0.0, 
					0.0, 0.0, 0.9, 0.0, 
					-14.5, -9.0, 0.0, 1.0 ),
    D3DXMATRIXA16( 0.9, 0.0, 0.0, 0.0, 
					0.0, 0.9, 0.0, 0.0, 
					0.0, 0.0, 0.9, 0.0,
                   -14.5, -9.0, 0.0, 1.0 )
    ]
    i=0
    for mesh in meshFile:
        fnAddMesh(mesh, mInitMatrWorld[i])
        print(i)
        i = i+1


        
