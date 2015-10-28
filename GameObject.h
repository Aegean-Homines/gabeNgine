#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "Component.h"
#include <unordered_map>

class TransformComponent;
class SpriteComponent;
class ControllerComponent;

class GameObject
{
public:
	GameObject();
	~GameObject();

	template<typename T>
	T* getComponent(Uint8 componentType){
		std::unordered_map<Uint8,Component*>::iterator retVal;

		retVal = componentList.find(componentType);
		if (retVal == componentList.end()){
			std::cout << "This component doesn't have a value matched with this key." << std::endl;
			return NULL;
		}

		return static_cast<T*>((*retVal).second);
	}
private:
	std::unordered_map < Uint8,Component* > componentList;
};

#endif GAME_OBJECT_H_

