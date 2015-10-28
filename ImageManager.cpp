#include "ImageManager.h"
#include "SDL_surface.h"
#include "Exceptions.h"
#include <iostream>

ImageManager* ImageManager::instance = NULL;

void ImageManager::addTransparency(SDL_Surface* surface, int flag, Uint8 r, Uint8 g, Uint8 b)
{
	if (SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b)) < 0){
		std::cout << "Problem occured while adding transparency to the specified color." << std::endl;
		throw ImageManagerException(SDL_GetError());
	}
}

ImageManager* ImageManager::getImageManagerInstance(void)
{
	if (instance == NULL)
		instance = new ImageManager();
	return instance;
}

ImageManager::ImageManager()
{
	std::cout << "ImageManager Default Constructor()" << std::endl;
}


ImageManager::ImageManager(ImageManager const&)
{
	std::cout << "ImageManager Copy Constructor()" << std::endl;
}

ImageManager& ImageManager::operator=(ImageManager const&)
{
	ImageManager imageManager;
	std::cout << "ImageManager Assignment Operator()" << std::endl;
	return imageManager;
}

ImageManager::~ImageManager()
{
	std::cout << "ImageManager Destructor()" << std::endl;
}


