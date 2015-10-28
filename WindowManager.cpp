#include "WindowManager.h"

#include <iostream>
#include "Exceptions.h"
#include "Window.hpp"

WindowManager* WindowManager::instance = NULL;

sf::Window* WindowManager::CreateWindow(const char* windowTitle, int width, int height)
{
	char* title = windowTitle ? windowTitle : "gabeNgine3";
	sf::Window* window = new sf::Window(sf::VideoMode(width, height), title);
	windowList.push_back(window);
	return window;
}

WindowManager* WindowManager::getWindowManagerInstance()
{
	if (instance == NULL){
		instance = new WindowManager();
	}

	return instance;
}


WindowManager::WindowManager()
{
	std::cout << "WindowManager Default Constructor()" << std::endl;
}

WindowManager::WindowManager(WindowManager const&)
{
	std::cout << "WindowManager Copy Constructor()" << std::endl;
}

WindowManager& WindowManager::operator=(WindowManager const&)
{
	WindowManager windowManager;
	std::cout << "WindowManager Assignment Op()" << std::endl;
	
	return windowManager;
}

WindowManager::~WindowManager()
{
	for (auto window : windowList){
		delete window;
		window = NULL;
	}
	std::cout << "WindowManager Destructor()" << std::endl;
}
