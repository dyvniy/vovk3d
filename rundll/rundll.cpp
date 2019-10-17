// rundll.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include "../interfaces/fordll.h"
//#pragma comment(lib, "../shadowmap/Release/pyShadowMap.lib")

int cb(double d, float f)
{
	//printf("onRender %f %f %i\n", d, f, int(1/f));
	return int(f+d)+2;
}

int ceBeforeCreate(int i);

int ceOnCreate(int i){printf("onCreate %i\n",i);return 0;}
int ceOnReset(int i){printf("onReset\n");return 0;}
int ceOnLost(int i){printf("onLost\n");return 0;}
int ceOnDestroy(int i){printf("onDestroy\n");return 0;}

int _tmain(int argc, _TCHAR* argv[])
{
	beforeCreateCb(ceBeforeCreate);
	onCreateCb(ceOnCreate);
	onResetCb(ceOnReset);
	onRenderCb(cb);
	onLostCb(ceOnLost);
	onDestroyCb(ceOnDestroy);

	printf("%i\n", fncallback(cb));
	runApp();
	//getchar();
	return 0;
}

int ceBeforeCreate(int i)
{
	printf("beforeCreate %i\n",i);
	wchar_t* aszMeshFile[] =
	{
		L"room.x",
		L"airplane\\airplane 2.x",
		L"misc\\car.x",
		L"misc\\sphere.x",
		L"UI\\arrow.x",
		L"UI\\arrow.x",
		//L"UI\\arrow.x",
		////L"UI\\arrow.x",
		//L"UI\\arrow.x",
		//L"UI\\arrow.x",
		//L"UI\\arrow.x",
		//L"UI\\arrow.x",
		//L"UI\\arrow.x",
		//L"UI\\arrow.x",
		//L"UI\\arrow.x",
		L"ring.x",
		L"ring.x",
	};

	#define NUM_OBJ (sizeof(aszMeshFile)/sizeof(aszMeshFile[0]))

	float amInitObjWorld[] =
	{
    	3.5f, 0.0f, 0.0f, 0.0f, //room
					0.0f, 3.0f, 0.0f, 0.0f, 
					0.0f, 0.0f, 3.5f, 0.0f, 
					0.0f, 0.0f, 0.0f, 1.0f ,
      0.43301f, 0.25f, 0.0f, 0.0f, //airplane
					-0.25f, 0.43301f, 0.0f, 0.0f, 
					0.0f, 0.0f, 0.5f, 0.0f, 
					5.0f, 1.33975f, 0.0f, 1.0f ,
      0.8f, 0.0f, 0.0f, 0.0f, // car
					0.0f, 0.8f, 0.0f, 0.0f, 
					0.0f, 0.0f, 0.8f, 0.0f, 
					-14.5f, -7.1f, 0.0f,1.0f ,
      2.0f, 0.0f, 0.0f, 0.0f, // sphere
					0.0f, 2.0f, 0.0f, 0.0f, 
					0.0f, 0.0f, 2.0f, 0.0f, 
					0.0f, -7.0f, 0.0f,1.0f ,
     5.5f, 0.0f, 0.0f, 0.0f, // arrow1
					0.0f, 0.0f, 5.5f, 0.0f, 
					0.0f, -9.0f, 0.0f, 0.0f, 
					5.0f, 0.2f, 5.0f, 1.0f ,
     5.5f, 0.0f, 0.0f, 0.0f, 
					0.0f, 0.0f, 5.5f, 0.0f, 
					0.0f, -9.0f, 0.0f, 0.0f, 
					5.0f, 0.2f, -5.0f, 1.0f ,
     //5.5f, 0.0f, 0.0f, 0.0f, 
					//0.0f, 0.0f, 5.5f, 0.0f, 
					//0.0f, -9.0f, 0.0f, 0.0f, 
					//-5.0f, 0.2f, 5.0f, 1.0f ,
     //5.5f, 0.0f, 0.0f, 0.0f, 
					//0.0f, 0.0f, 5.5f, 0.0f, 
					//0.0f, -9.0f, 0.0f, 0.0f, 
					//-5.0f, 0.2f, -5.0f, 1.0f ,
     //5.5f, 0.0f, 0.0f, 0.0f, 
					//0.0f, 0.0f, 5.5f, 0.0f, 
					//0.0f, -9.0f, 0.0f, 0.0f, 
					//14.0f, 0.2f, 14.0f,1.0f ,
     //5.5f, 0.0f, 0.0f, 0.0f, 
					//0.0f, 0.0f, 5.5f, 0.0f, 
					//0.0f, -9.0f, 0.0f, 0.0f, 
					//14.0f, 0.2f, -14.0f, 1.0f ,
     //5.5f, 0.0f, 0.0f, 0.0f, 
					//0.0f, 0.0f, 5.5f, 0.0f, 
					//0.0f, -9.0f, 0.0f, 0.0f, 
					//-14.0f, 0.2f, 14.0f, 1.0f ,
     //5.5f, 0.0f, 0.0f, 0.0f, 
					//0.0f, 0.0f, 5.5f, 0.0f, 
					//0.0f, -9.0f, 0.0f, 0.0f, 
					//-14.0f, 0.2f, -14.0f, 1.0f ,
     0.9f, 0.0f, 0.0f, 0.0f, 
					0.0f, 0.9f, 0.0f, 0.0f, 
					0.0f, 0.0f, 0.9f, 0.0f, 
					-14.5f, -9.0f, 0.0f, 1.0f ,
     0.9f, 0.0f, 0.0f, 0.0f, 
					0.0f, 0.9f, 0.0f, 0.0f, 
					0.0f, 0.0f, 0.9f, 0.0f, 
					14.5f, -9.0f, 0.0f, 1.0f ,
	};
	for (int i=0; i<NUM_OBJ; ++i)
		addMesh(aszMeshFile[i], &amInitObjWorld[16*i]);
	return 0;
}
