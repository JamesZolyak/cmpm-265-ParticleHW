#pragma once
#include "BaseParticleFunction.h"
class FireParticleFunction :
	public BaseParticleFunction
{
public:

	void changeSize(TinyParticle *particle, float elapsed)
	{
		particle->particleShape->setSize(sf::Vector2f(particle->particleShape->getSize().x + 0.04f, particle->particleShape->getSize().y + 0.04f));
		
	}

	void changeVelocity(TinyParticle *particle)
	{
		particle->speed += 0.03f;
		particle->velocity = sf::Vector2f(std::cos(particle->curAngle) * particle->speed, std::sin(particle->curAngle) * particle->speed);
	}

	FireParticleFunction();
	~FireParticleFunction();
};

