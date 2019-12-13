#pragma once

#include "vector3d.h"

struct Matrix4x4
{
	struct v16 { double v; };
	struct v4x4 { Vector4d v[4]; };
};