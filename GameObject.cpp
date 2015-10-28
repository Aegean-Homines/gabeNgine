#include "GameObject.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "ControllerComponent.h"
#include <iostream>
#include "SDL_stdinc.h"


GameObject::GameObject()
{
	//TODO ilk yaratıldığında olmasın bunlar, get falan diyince NULLsa döndürürüz zanza
	TransformComponent* myTransformComponent = new TransformComponent();
	myTransformComponent->setMyOwner(this);
	SpriteComponent* mySpriteComponent = new SpriteComponent();
	mySpriteComponent->setMyOwner(this);
	componentList.insert({ TRANSFORM, myTransformComponent });
	componentList.insert({ SPRITE, mySpriteComponent });
}


GameObject::~GameObject()
{
	for (auto component: this->componentList)
	{ 
		//TODO TEST THE CRAP OUT OF IT - not sure if this is the case
		delete component.second;
	}
}