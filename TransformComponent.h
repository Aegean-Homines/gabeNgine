#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

#include "Component.h"

class TransformComponent : public Component{
public:
	TransformComponent(){ x = 0.0f, y = 0.0f; componentType = TRANSFORM; myOwner = NULL; }
	TransformComponent(const TransformComponent& otherComponent){
		this->x = otherComponent.getX();
		this->y = otherComponent.getY();
	}
	float getX() const { return x; }
	void setX(float val) { x = val; }
	float getY() const { return y; }
	void setY(float val) { y = val; }
private:
	float x;
	float y;
};

#endif