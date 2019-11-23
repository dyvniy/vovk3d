#pragma once

struct IVector3d {
	struct v2 { double v[2]; };
	struct v3 { double v[3]; };
	double& x();
	double& y();
	double& z();
	v2& xy();
	v2& xz();
	v3& xyz();
};