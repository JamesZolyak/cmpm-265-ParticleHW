#include "ParticleManager.h"
#include "PSystem.h"


ParticleManager::ParticleManager()
{

}

void ParticleManager::update(float elapsed)
{
	for each (PSystem var in systemVector)
	{
		var.update(elapsed);
	}
}

ParticleManager::~ParticleManager()
{
}
