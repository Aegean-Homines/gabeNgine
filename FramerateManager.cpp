#include "FramerateManager.h"
#include "SDL_timer.h"

#include <iostream>

FramerateManager* FramerateManager::instance = NULL;

FramerateManager* FramerateManager::getFramerateManagerInstance(void)
{
	if (instance == NULL)
		instance = new FramerateManager();
	return instance;
}

void FramerateManager::frameStart(void)
{
	frameStartTime = SDL_GetTicks();
}

void FramerateManager::frameEnd(void)
{
	do{
		frameEndTime = SDL_GetTicks();
	} while (frameEndTime - frameStartTime < timePerFrame);

}

void FramerateManager::setFramerate(Uint32 val)
{
	if (val > MAX_FRAME_RATE)
		val = MAX_FRAME_RATE;
	if (val == 0)
		val = 1;
	framerate = val; 
	timePerFrame = 1000 / framerate;
}

FramerateManager::FramerateManager()
{
	framerate = 60; //default fps
	frameStartTime = 0;
	frameEndTime = 0;
	timePerFrame = 1000 / framerate;
	std::cout << "FramerateManager Default Constructor()" << std::endl;
}


FramerateManager::FramerateManager(FramerateManager const&)
{
	std::cout << "FramerateManager Copy Constructor()" << std::endl;
}

FramerateManager& FramerateManager::operator=(FramerateManager const&)
{
	FramerateManager framerateManager;
	std::cout << "FramerateManager Assignment Operator()" << std::endl;
	return framerateManager;
}

FramerateManager::~FramerateManager()
{
	std::cout << "FramerateManager Destructor()" << std::endl;
}

