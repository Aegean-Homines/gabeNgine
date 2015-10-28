#include "SurfaceManager.h"

#include <iostream>
#include "Exceptions.h"
#include "SDL_video.h"
#include "SDL_image.h"

SurfaceManager* SurfaceManager::instance = NULL;

SDL_Surface* SurfaceManager::getSurfaceFromWindow(SDL_Window* window)
{
	//TODO not sure if this surface needs to be controlled
	SDL_Surface* surface;
	surface = SDL_GetWindowSurface(window);
	if (surface == NULL){
		std::cout << "Window surface couldn't be retrieved." << std::endl;
		throw SurfaceManagerException(SDL_GetError());
	}

	return surface;
}

SurfaceManager* SurfaceManager::getSurfaceManagerInstance(){
	if (instance == NULL)
		instance = new SurfaceManager();
	return instance;
}

//TODO might delete imagetype - fileName usually has an extension, might parse it
SDL_Surface* SurfaceManager::getSurfaceWithImage(const char* fileName, unsigned int imageType)
{
	SDL_Surface* imageSurface;

	switch (imageType)
	{
	case PNG:
		imageSurface = IMG_Load("erensprite.png");
		if (imageSurface == NULL){
			std::cout << "Image couldn't be loaded." << std::endl;
			throw SurfaceManagerException(IMG_GetError());
		}
		break;
	case BMP:
		imageSurface = SDL_LoadBMP(fileName);
		if (imageSurface == NULL){
			std::cout << "Image couldn't be loaded." << std::endl;
			throw SurfaceManagerException(SDL_GetError());
		}
		break;
	default:
		std::cout << "Invalid image type." << std::endl;
		imageSurface = NULL;
	}

	surfaceList.push_back(imageSurface);
	
	return imageSurface;
}

SurfaceManager::SurfaceManager()
{
	std::cout << "SurfaceManager Default Constructor()" << std::endl;
}

SurfaceManager::SurfaceManager(SurfaceManager const&)
{
	std::cout << "SurfaceManager Copy Constructor()" << std::endl;
}

SurfaceManager& SurfaceManager::operator=(SurfaceManager const&)
{
	SurfaceManager surfaceManager;
	std::cout << "SurfaceManager Assignment Op()" << std::endl;
	return surfaceManager;
}

SurfaceManager::~SurfaceManager()
{
	for (auto surface : surfaceList){
		SDL_FreeSurface(surface);
		surface = NULL;
	}
	std::cout << "SurfaceManager Destructor()" << std::endl;
}

