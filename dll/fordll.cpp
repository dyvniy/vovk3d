#include "DXUT.h"

#define DLL_EXPORTS
#include "../interfaces/fordll.h"


extern "C" {

	// This is an example of an exported variable
	DLL_API int ndll=0;

	// This is an example of an exported function.
	DLL_API int fndll(void)
	{
		return 42; // число до 100, которое сложнее всего представить суммой трёх кубов
	}

	///////////////////////////////// callbacks /////////////////////////////////////

	DLL_API int fncallback(func_pointer_render p)
	{
		return p(25.1, 10.6f)*2;
	}

	DLL_API int fnCallabck0(func_pointer_empty p)
	{
		return p(0);
	}

	////////////////////////////////// app ////////////////////////////////////////
	DLL_API int runApp()
	{
		return wWinMain( 0,0,0,0 );
	}

	DLL_API int initApp()
	{
		return wndInitApp();
	}
	DLL_API int loopApp()
	{
		return wndLoopApp();
	}
	DLL_API int closeApp()
	{
		OnDestroyDevice( 0 );
		return 0;
	}
	//////////////////////////////////////////////////////////////////////////

	DLL_API float* matrix() {
		return new float[16]{ 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
	}
	DLL_API int delarr(float* matr) {
		delete[] matr;
		return 0;
	}
};

//BOOL APIENTRY DllMain( HMODULE hModule,
//                       DWORD  ul_reason_for_call,
//                       LPVOID lpReserved
//					 )
//{
//	switch (ul_reason_for_call)
//	{
//	case DLL_PROCESS_ATTACH:
//	case DLL_THREAD_ATTACH:
//	case DLL_THREAD_DETACH:
//	case DLL_PROCESS_DETACH:
//		break;
//	}
//	return TRUE;
//}
