#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"

struct SDL_Surface;
class GameObject;

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	~SpriteComponent();

	SDL_Surface* getMySurface() const { return mySurface; }
	void setMySurface(SDL_Surface* val) { mySurface = val; }
private:
	SDL_Surface* mySurface;

};

#endif
