#include "PSystem.h"
#include <iostream>

using namespace std;
PSystem::PSystem(unsigned int count, sf::Texture &textureToUse, int angleMin, int angleMax, int speedBase, 
	sf::Color colorTint, sf::Vector2f position, int type, sf::Vector2f size, int lifetime)
{
	m_lifetime = sf::seconds(lifetime);
	angleLow = angleMin;
	angleHigh = angleMax;
	speedAmount = speedBase;
	colorChange = colorTint;
	curTexture = textureToUse;
	m_emitter = position;
	storedSize = size;
	
	if (type == ParticleFunctionType::Particle)
		bParticleFunction = new ParticleFunction();
	else if (type == ParticleFunctionType::Water)
		bParticleFunction = new WaterParticleFunction();
	else if (type == ParticleFunctionType::Fire)
		bParticleFunction = new FireParticleFunction();

	for (int i = 0; i < count; i++){
		baseAngle = ((std::rand() % (angleHigh - angleLow)) + angleLow)* 3.14f / 180.f;
		
		theParticles.push_back(new TinyParticle(lifetime, textureToUse, size.x, size.y, m_emitter, speedAmount, baseAngle));
	}
}

void PSystem::setEmitter(sf::Vector2f position)
{
	m_emitter = position;
}

void PSystem::update(float elapsed)
{
	for (std::size_t i = 0; i < theParticles.size(); ++i)
	{
		theParticles[i]->lifetime = theParticles[i]->lifetime - elapsed;

		// if the particle is dead, respawn it
		if (theParticles[i]->lifetime <= 0)
			resetParticle(i);

		// update the position of the corresponding vertex

		//theParticles[i].particleShape.setPosition(theParticles[i].particleShape.getPosition() + theParticles[i].velocity * elapsed);
		theParticles[i]->position = theParticles[i]->position + theParticles[i]->velocity * elapsed;
		theParticles[i]->particleShape->setPosition(theParticles[i]->position);
		// update the alpha (transparency) of the particle according to its lifetime
		float ratio = theParticles[i]->lifetime / m_lifetime.asSeconds();
		theParticles[i]->particleShape->setFillColor(sf::Color(colorChange.r, colorChange.g, colorChange.b, static_cast<sf::Uint8>(ratio * 255)));
		
		bParticleFunction->changeSize(theParticles[i], elapsed);
		bParticleFunction->changeVelocity(theParticles[i]);
	}
}

void PSystem::resetParticle(std::size_t index)
{
	// give a random velocity and lifetime to the particle
	
	float angle = ((std::rand() % (angleHigh - angleLow)) + angleLow)* 3.14f / 180.f;
	float speed = (std::rand() % 50) + speedAmount;
	theParticles[index]->velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	double u = ((rand() % (160000 - 130000) / 10000.0) + 1);

	theParticles[index]->lifetime = u;
	
	// reset the position of the corresponding vertex
	theParticles[index]->particleShape->setPosition(m_emitter);
	theParticles[index]->position = m_emitter;
	theParticles[index]->particleShape->setScale(sf::Vector2f(1, 1));
	theParticles[index]->particleShape->setSize(storedSize);
	theParticles[index]->speed = speed;
}

void PSystem::add()
{
	baseAngle = ((std::rand() % (angleHigh - angleLow)) + angleLow)* 3.14f / 180.f;
	//theParticles.push_back(new TinyParticle(lifetime, textureToUse, size.x, size.y, m_emitter, speedAmount, baseAngle));
	theParticles.push_back(new TinyParticle(m_lifetime.asSeconds(), curTexture, storedSize.x, storedSize.y, m_emitter, speedAmount, baseAngle));
}

void PSystem::remove()
{
	theParticles.pop_back();
}

PSystem::~PSystem()
{
}
