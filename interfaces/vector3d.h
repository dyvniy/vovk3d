#pragma once

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

struct IVector4d {
	struct v2 { double v[2]; };
	struct v3 { double v[3]; };
	struct v4 { double v[4]; };
	double& x();
	double& y();
	double& z();
	double& w();
	v2& xy();
	v2& xz();
	v3& xyz();
	v4& xyzw();
};

struct IVector3d {
	double& x();
	double& y();
	double& z();
	IVector4d::v2& xy();
	IVector4d::v2& xz();
	IVector4d::v3& xyz();
};


