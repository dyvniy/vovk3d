// rundll.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include "fordll.h"
//#pragma comment(lib, "../sln/x64/Debug/Vovk3d.lib")
#include <string>

#include <unordered_map>

struct PyMeshData
{
	float matr[16];
	int index;
};

std::unordered_map<std::wstring, PyMeshData> meshd;

int cb(double d, float f)
{
	//printf("onRender %f %f %i\n", d, f, int(1/f));
	return int(f+d)+2;
}

int ceBeforeCreate(int i);
int ceOnMove(double fTime, float fElapsedTime);

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
	onMoveCb(ceOnMove);

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
	PyMeshData data;
};

int ceBeforeCreate(int i)
{
	int j = 0;
	const PyMesh meshes[] = {
		//PyMesh {
		//	L"room.x",
		//	PyMeshData {
		//	{
		//		3.5f, 0.0f, 0.0f, 0.0f, //room
		//		0.0f, 3.0f, 0.0f, 0.0f,
		//		0.0f, 0.0f, 3.5f, 0.0f,
		//		0.0f, 0.0f, 0.0f, 1.0f
		//  },
		//  j++
		//},
		//PyMesh {
		//	L"airplane\\airplane 2.x",
		//	PyMeshData {
		//	{
		//		0.43301f, 0.25f, 0.0f, 0.0f, //airplane
		//		-0.25f, 0.43301f, 0.0f, 0.0f,
		//		0.0f, 0.0f, 0.5f, 0.0f,
		//		5.0f, 1.33975f, 0.0f, 1.0f
		//  },
		//  j++
		//},
		//PyMesh {
		//	L"misc\\car.x",
		//	PyMeshData {
		//	{
		//		0.8f, 0.0f, 0.0f, 0.0f, // car
		//		0.0f, 0.8f, 0.0f, 0.0f, 
		//		0.0f, 0.0f, 0.8f, 0.0f, 
		//		-14.5f, -7.1f, 0.0f,1.0f 
		//  },
		//  j++
		//},
		//PyMesh{
		//	L"misc\\sphere.x",
		//	PyMeshData {
		//	{
		//		2.0f, 0.0f, 0.0f, 0.0f, // sphere
		//		0.0f, 2.0f, 0.0f, 0.0f, 
		//		0.0f, 0.0f, 2.0f, 0.0f, 
		//		0.0f, -7.0f, 0.0f,1.0f ,
		//  },
		//  j++
		//},
		//PyMesh{
		//	L"UI\\arrow.x",
		//	PyMeshData {
		//	{
		//		5.5f, 0.0f, 0.0f, 0.0f, // arrow1
		//		0.0f, 0.0f, 5.5f, 0.0f,
		//		0.0f, -9.0f, 0.0f, 0.0f,
		//		5.0f, 0.2f, 5.0f, 1.0f ,
		//  },
		//  j++
	//},
		PyMesh {
			L"divanovka.x",
			PyMeshData {
			{
				0.9f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.9f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.9f, 0.0f,
				1.0f, 0.0f, 0.0f, 1.0f
			},
			j++}
		}
	};

	#define NUM_MESH (sizeof(meshes)/sizeof(meshes[0]))

	for (int i = 0; i < NUM_MESH; ++i) {
		addMesh(meshes[i].namepath, meshes[i].data.matr);
		meshd[meshes[i].namepath] = meshes[i].data;
	}

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

const double D3DX_PI = 3.141592653;

int ceOnMove(double fTime, float fElapsedTime)
{
	rotateY(meshd[L"divanovka.x"].index, fElapsedTime);
	static double last_time = fTime;
	if (abs(last_time - fTime) > 1) {
		printf("%f \t", fTime);
		last_time = fTime;
	}
	//rotateY(1, D3DX_PI * fElapsedTime / 4.0f);
	//rotateY(2, -D3DX_PI * fElapsedTime / 4.0f);
	//float v[] = { 0.1f, 1.0f, -0.2f };
	//rotateAxis(3, -D3DX_PI * fElapsedTime / 6.0f, v);
	//rotateY(4, -D3DX_PI * fElapsedTime / 4.0f);
	return 0;
}