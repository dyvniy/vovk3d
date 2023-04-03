#pragma once
#ifndef SOUND_H

#include "vector4d.h"

struct ISound
{
	virtual bool SetPos(const IVector4d& pos) = 0;
	virtual bool Play(bool pause = false) = 0;
	virtual bool Load(char* path) = 0;
};

#define SOUND_H
#endif//SOUND_H
