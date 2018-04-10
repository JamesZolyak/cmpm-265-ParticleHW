#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "PSystem.h"
#include "ParticleManager.h"
#include "TinyParticle.h"
using namespace sf;
using namespace std;

int main()
{
	Texture waterParticleTexture;
	Texture particleTexture;
	Texture fireParticleTexture;
	bool runOnce = false;
	waterParticleTexture.loadFromFile("Smoke (1) - Gavtrain.jpg");
	particleTexture.loadFromFile("Smoke (6) - Gavtrain.jpg");
	fireParticleTexture.loadFromFile("Smoke (5) - Gavtrain.jpg");

	// create the window
	sf::RenderWindow window(sf::VideoMode(1440, 960), "Particles");

	PSystem particles(20, particleTexture, 180, 220,30, Color(156, 170, 230, 255),sf::Vector2f(1340,800),0, sf::Vector2f(60, 60),3);
	PSystem water(20, waterParticleTexture,45,90,40, Color(0,100,200,255), sf::Vector2f(50, 50), 1, sf::Vector2f(30, 30),2);
	PSystem fire(20, fireParticleTexture,90,120,30, Color(200, 100, 0, 255), sf::Vector2f(50, 800), 2, sf::Vector2f(20, 20),4);

	// create a clock to track the elapsed time
	sf::Clock clock;

	sf::Time elapsed;
	
	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Up && !runOnce)
			{
				particles.add();
				water.add();
				fire.add();
				runOnce = true;
			}
			if (event.key.code == sf::Keyboard::Down && particles.theParticles.size() > 0 && !runOnce)
			{
				particles.remove();
				water.remove();
				fire.remove();
				runOnce = true;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Up && runOnce)
				runOnce = false;
			if (event.key.code == sf::Keyboard::Down)
				runOnce = false;
		}

		// update it
		float deltaTime = clock.restart().asSeconds();

		particles.update(deltaTime);
		water.update(deltaTime);
		fire.update(deltaTime);
		
		window.clear();
		particles.draw(window,RenderStates::Default);
		water.draw(window, RenderStates::Default);
		fire.draw(window, RenderStates::Default);
		
		window.display();
	}

	return 0;
}
