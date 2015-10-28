#ifndef IMAGE_MANAGER_H_
#define IMAGE_MANAGER_H_

#include "SDL_stdinc.h"

struct SDL_Surface;

class ImageManager
{
public:
	static ImageManager* getImageManagerInstance(void);
	void addTransparency(SDL_Surface* surface, int flag, Uint8 r, Uint8 g, Uint8 b);
private:
	static ImageManager* instance;
	ImageManager();
	ImageManager(ImageManager const&);
	ImageManager& operator=(ImageManager const&);
	~ImageManager();
};
#endif // IMAGE_MANAGER_H_