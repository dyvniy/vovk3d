#pragma once
#ifndef SOUND_H

#include "vector3d.h"

interface ISound
{
	bool SetPos(const IVector3d& pos);
	bool Play(bool pause = false);
};

#define SOUND_H
#endif//SOUND_H
