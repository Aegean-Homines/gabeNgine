#ifndef SURFACE_MANAGER_H_
#define SURFACE_MANAGER_H_

#include "SDL_stdinc.h"
#include "list"

struct SDL_Surface;
struct SDL_Window;

enum IMAGE_TYPE{
	PNG,
	BMP
};


class SurfaceManager
{
public:
	SDL_Surface* getSurfaceFromWindow(SDL_Window* window);
	static SurfaceManager* getSurfaceManagerInstance(void);
	SDL_Surface* getSurfaceWithImage(const char* fileName, unsigned int imageType);
private:
	SurfaceManager();
	SurfaceManager(SurfaceManager const&);
	SurfaceManager& operator=(SurfaceManager const&);
	~SurfaceManager();
	static SurfaceManager* instance;
	std::list<SDL_Surface*> surfaceList;
};

#endif // SURFACE_MANAGER_H_

