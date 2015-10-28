#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "SDL_stdinc.h"

class GameObject;

enum COMPONENT_TYPE{
	TRANSFORM,
	SPRITE,
	CONTROLLER
};

class Component
{
public:
	Component();
	virtual ~Component();
	Uint8 getMyType() const { return componentType; }
	GameObject* getMyOwner() const { return myOwner; }
	void setMyOwner(GameObject* val) { myOwner = val; }
protected:
	Uint8 componentType;
	GameObject* myOwner;
};

#endif

