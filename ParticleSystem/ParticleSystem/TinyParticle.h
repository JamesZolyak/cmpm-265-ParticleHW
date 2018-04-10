#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
class TinyParticle
{
public:
	sf::Vector2f velocity;
	float lifetime;
	sf::Texture texture;
	sf::RectangleShape *particleShape;
	sf::Vector2f position;
	float speed;
	float curAngle;
	TinyParticle(float lifetime, sf::Texture &texture, int width, int height, sf::Vector2f spawnPosition, float pSpeed, float angle);
	~TinyParticle();
};

