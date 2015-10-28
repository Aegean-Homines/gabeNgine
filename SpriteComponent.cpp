#include "SpriteComponent.h"
#include <iostream>
#include "SDL_surface.h"

SpriteComponent::SpriteComponent()
{
	myOwner = NULL;
	mySurface = NULL;
}


SpriteComponent::~SpriteComponent()
{
}
