// rundll.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include "fordll.h"
//#pragma comment(lib, "../sln/x64/Debug/Vovk3d.lib")

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
	try {
		runApp();
	} 
	catch (...) {
		printf("=== Error !!! ===");
	}
	ceOnLost(0);
	ceOnDestroy(0);
	//getchar();
	return 0;
}

struct PyMesh {
	wchar_t* namepath;
	float matr[16];
};

int ceBeforeCreate(int i)
{
	const PyMesh meshes[] = {
		PyMesh {
			L"room.x",
			{
				3.5f, 0.0f, 0.0f, 0.0f, //room
				0.0f, 3.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 3.5f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},
		PyMesh {
			L"airplane\\airplane 2.x",
			{
				0.43301f, 0.25f, 0.0f, 0.0f, //airplane
				-0.25f, 0.43301f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.5f, 0.0f,
				5.0f, 1.33975f, 0.0f, 1.0f
			}
		},
		PyMesh {
			L"misc\\car.x",
			{
				0.8f, 0.0f, 0.0f, 0.0f, // car
				0.0f, 0.8f, 0.0f, 0.0f, 
				0.0f, 0.0f, 0.8f, 0.0f, 
				-14.5f, -7.1f, 0.0f,1.0f 
			}
		},
		PyMesh{
			L"misc\\sphere.x",
			{
				2.0f, 0.0f, 0.0f, 0.0f, // sphere
				0.0f, 2.0f, 0.0f, 0.0f, 
				0.0f, 0.0f, 2.0f, 0.0f, 
				0.0f, -7.0f, 0.0f,1.0f ,
			}
		},
		PyMesh{
			L"UI\\arrow.x",
			{
				5.5f, 0.0f, 0.0f, 0.0f, // arrow1
				0.0f, 0.0f, 5.5f, 0.0f,
				0.0f, -9.0f, 0.0f, 0.0f,
				5.0f, 0.2f, 5.0f, 1.0f ,
			}
		},
		PyMesh {
			L"divanovka.x",
			{
				0.9f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.9f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.9f, 0.0f,
				1.0f, 0.0f, 0.0f, 1.0f
			}
		}
	};

	#define NUM_MESH (sizeof(meshes)/sizeof(meshes[0]))

	for (int i=0; i< NUM_MESH; ++i)
		addMesh(meshes[i].namepath, meshes[i].matr);

	//float ma[16] = {
	//	0.8f, 0.0f, 0.0f, 0.0f, // car
	//	0.0f, 0.8f, 0.0f, 0.0f,
	//	0.0f, 0.0f, 0.8f, 0.0f,
	//	-14.5f, -5.1f, 0.0f, 1.0f , // flying (-7.1)
	//};
	//setMatrix(2, ma);

	//float matr[] = { 5.5f, 0.0f, 0.0f, 0.0f,
	//				0.0f, 0.0f, 5.5f, 0.0f,
	//				0.0f, -9.0f, 0.0f, 0.0f,
	//				5.0f, 0.2f, -0.0f, 1.0f };
	//int arrId = addMesh(L"UI\\arrow.x", matr);
	//float ma2[16] = {
	//	0.8f, 0.0f, 0.0f, 0.0f, // car
	//	0.0f, 0.8f, 0.0f, 0.0f,
	//	0.0f, 0.0f, 0.8f, 0.0f,
	//	-14.5f, -5.1f, 0.0f, 1.0f , // flying (-7.1)
	//};
	//setMatrix(arrId, ma2);

	return 0;
}
