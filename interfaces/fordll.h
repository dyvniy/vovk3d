#pragma once

#include "sound3d.h"

int WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, int );
int wndInitApp();
int wndLoopApp();
void CALLBACK OnDestroyDevice( void* pUserContext );

typedef int (*func_pointer_render)( double fTime, float fElapsedTime );
typedef int (*func_pointer_empty)( int i );

extern "C" {

	extern DLL_API int ndll;

	DLL_API int fndll(void);
	DLL_API int fncallback(func_pointer_render p);
	DLL_API int fnCallback0(func_pointer_empty p);
	// callbacks
	DLL_API int beforeCreateCb(func_pointer_empty p);
	DLL_API int onCreateCb(func_pointer_empty p);
	DLL_API int onResetCb(func_pointer_empty p);
	DLL_API int onMoveCb(func_pointer_render p);
	DLL_API int onRenderCb(func_pointer_render p);
	DLL_API int onLostCb(func_pointer_empty p);
	DLL_API int onDestroyCb(func_pointer_empty p);
	// beforeCreate
	DLL_API int addMesh(wchar_t filName[50], float matr[16]);
	DLL_API int setMatrix(int number, float matr[16]);
		// onMove
	DLL_API int rotateY(int idx, float mul);
	DLL_API int rotateAxis(int idx, float mul, float v[3]);
	// start application
	DLL_API int runApp();

	DLL_API int initApp();
	DLL_API int loopApp();
	DLL_API int closeApp();
};