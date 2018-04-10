#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "TinyParticle.h"
#include "BaseParticleFunction.h"
#include "ParticleFunction.h"
#include "WaterParticleFunction.h"
#include "FireParticleFunction.h"

class PSystem : public sf::Drawable, public sf::Transformable
{
public:

	enum ParticleFunctionType
	{
		Particle, Fire, Water
	};

	BaseParticleFunction *bParticleFunction;

	std::vector<TinyParticle*> theParticles;
	//std::vector<Particle> m_particles;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	sf::Vector2f storedSize;
	sf::Texture curTexture;
	int lifeTimeBase;
	int angleLow;
	int angleHigh;
	int speedAmount;
	float baseAngle;
	sf::Color colorChange;
	PSystem(unsigned int count, sf::Texture &textureToUse, int angleMin, int angleMax, int speedBase, 
		sf::Color colorTint, sf::Vector2f position, int type, sf::Vector2f size, int lifetime);

	void setEmitter(sf::Vector2f position);
	
	void update(float elapsed);

	void resetParticle(std::size_t index);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (int i = 0; i < theParticles.size(); i++)
		{
			target.draw(*theParticles[i]->particleShape, states);
		}
	}

	void add();
	void remove();

	~PSystem();
};