#include "TinyParticle.h"



TinyParticle::TinyParticle(float particleLifetime, sf::Texture &particleTexture, int width, int height, sf::Vector2f spawnPosition, float pSpeed, float angle)
{
	lifetime = particleLifetime;
	texture = particleTexture;
	particleShape = new sf::RectangleShape(sf::Vector2f(width, height));
	particleShape->setTexture(&particleTexture);
	//particleShape.setTextureRect(sf::IntRect(50, 50, 50, 50));
	particleShape->setPosition(spawnPosition);
	position = spawnPosition;
	speed = pSpeed;
	curAngle = angle;
}


TinyParticle::~TinyParticle()
{
	delete particleShape;
}
