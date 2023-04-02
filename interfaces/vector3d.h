#pragma once

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

struct IVector4d {
	double v[4];
	// types
	struct v2 { double v[2]; };
	struct v3 { double v[3]; };
	// methods
	virtual double& x() { return v[0]; };
	virtual double& y() { return v[1]; };
	virtual double& z() { return v[2]; };
	virtual double& w() { return v[3]; };
	virtual v2& xy();
	virtual v2& xz();
	virtual v2& yz();
	virtual v3& xyz();
	virtual IVector4d& xyzw();
};
