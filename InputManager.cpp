#include <iostream>

#include "InputManager.h"
#include "SDL_events.h"

InputManager* InputManager::instance = NULL;

InputManager* InputManager::getInputManagerInstance(void)
{
	if (instance == NULL)
		instance = new InputManager();
	return instance;
}

bool InputManager::isKeyDown(const char* key) const
{
	SDL_Scancode keyCode = SDL_GetScancodeFromName(key);
	return pressedKeys[keyCode];
}

bool InputManager::isKeyDown(SDL_Scancode keyCode) const
{
	return pressedKeys[keyCode];
}

bool InputManager::isKeyUp(const char* key) const
{
	return !isKeyDown(key);
}

bool InputManager::isKeyReleased(const char* key) const
{
	SDL_Scancode keyCode = SDL_GetScancodeFromName(key);
	if (previousKeys[keyCode] && !pressedKeys[keyCode])
		return true;
	else
		return false;
}

bool InputManager::isKeyPressed(const char* key) const
{
	SDL_Scancode keyCode = SDL_GetScancodeFromName(key);
	return (!previousKeys[keyCode] && pressedKeys[keyCode]);
}

void InputManager::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		std::cout << e.type << std::endl;

		//TODO redirect this from here
		if (e.type == SDL_QUIT){
			pressedKeys[SDL_SCANCODE_ESCAPE] = true;
		}
		else{
			if (e.type == SDL_KEYDOWN){
				previousKeys[e.key.keysym.scancode] = pressedKeys[e.key.keysym.scancode];
				pressedKeys[e.key.keysym.scancode] = true;
			}
			else if (e.type == SDL_KEYUP){
				previousKeys[e.key.keysym.scancode] = pressedKeys[e.key.keysym.scancode];
				pressedKeys[e.key.keysym.scancode] = false;
			}
		}
	
	}
}

InputManager::InputManager()
{
	for (int i = 0; i < SDL_NUM_SCANCODES; ++i){
		pressedKeys[i] = false;
		previousKeys[i] = false;
	}
	std::cout << "InputManager Default Constructor()" << std::endl;
}


InputManager::InputManager(InputManager const&)
{
	std::cout << "InputManager Copy Constructor()" << std::endl;
}

InputManager& InputManager::operator=(InputManager const&)
{
	//TEMP - DON'T MIND THE WARNING
	InputManager inputManager;
	std::cout << "InputManager Assignment Operator()" << std::endl;
	return inputManager;
}

InputManager::~InputManager()
{
	std::cout << "InputManager Destructor()" << std::endl;
}
