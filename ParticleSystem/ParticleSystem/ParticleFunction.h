#pragma once
#include "BaseParticleFunction.h"
class ParticleFunction :
	public BaseParticleFunction
{
public:

	void changeSize(TinyParticle *particle, float elapsed)
	{
		particle->particleShape->setSize(sf::Vector2f(particle->particleShape->getSize().x - 0.02f, particle->particleShape->getSize().y - 0.02f));
		/*particle->particleShape->setSize(sf::Vector2f(particle->particleShape->getSize().x, particle->particleShape->getSize().y) - 
			((particle->lifetime - elapsed) / particle->lifetime)*sf::Vector2f(10, 10));*/
	}

	void changeVelocity(TinyParticle *particle)
	{
		particle->speed -= 0.02f;
		particle->velocity = sf::Vector2f(std::cos(particle->curAngle) * particle->speed, std::sin(particle->curAngle) * particle->speed);
		
	}

	ParticleFunction();
	~ParticleFunction();
};

