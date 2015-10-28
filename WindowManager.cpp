#include "WindowManager.h"
#include <iostream>
#include "Exceptions.h"
#include "SDL_video.h"

WindowManager* WindowManager::instance = NULL;

SDL_Window* WindowManager::CreateWindow(const char* windowTitle, int windowPositionX, int windowPositionY, int width, int height, Uint32 flags)
{
	char* title = windowTitle ? windowTitle : "gabeNgine3";
	SDL_Window* window = SDL_CreateWindow(title, windowPositionX, windowPositionY, width, height, flags);
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
	for (SDL_Window* window : windowList){
		window = NULL;
	}
	std::cout << "WindowManager Destructor()" << std::endl;
}

void WindowManager::FillWindowWithColor(SDL_Window* window, Uint32 color)
{
	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(windowSurface, NULL, color);
}
