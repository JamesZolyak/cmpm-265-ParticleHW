#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "PSystem.h"

class ParticleManager
{
public:
	std::vector<PSystem> systemVector;

	ParticleManager();
	void update(float elapsed);
	~ParticleManager();
};

