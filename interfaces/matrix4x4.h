#pragma once

#include "vector4d.h"

struct Matrix4x4
{
	union {
		struct v16 { double v; };
		struct v4x4 { Vector4d v[4]; };
	};
};