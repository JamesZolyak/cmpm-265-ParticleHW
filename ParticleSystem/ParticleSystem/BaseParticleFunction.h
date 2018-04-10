#pragma once
#include "TinyParticle.h"
class BaseParticleFunction
{
public:
	
	virtual void changeSize(TinyParticle *particle, float elapsed) = 0;
	virtual void changeVelocity(TinyParticle *particle) = 0;

	BaseParticleFunction();
	~BaseParticleFunction();
};

