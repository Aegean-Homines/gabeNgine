#ifndef CONTROLLER_COMPONENT_H_
#define CONTROLLER_COMPONENT_H_

#include "Component.h"

class GameObject;

class ControllerComponent : public Component
{
public:
	ControllerComponent();
	~ControllerComponent();
private:
	GameObject* myOwner;
};

#endif