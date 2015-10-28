#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include <list>
#include "SDL_stdinc.h"

struct SDL_Window;

class WindowManager
{
public:

	//Creates window with a custom window title, if title = null creates one with default title
	SDL_Window* CreateWindow(const char* windowTitle, int windowPositionX, int windowPositionY, int width, int height, Uint32 flags);
	void FillWindowWithColor(SDL_Window* window, Uint32 color);
	static WindowManager* getWindowManagerInstance();
private:
	WindowManager();
	WindowManager(WindowManager const&);
	WindowManager& operator=(WindowManager const&);
	~WindowManager();
	static WindowManager* instance;
	std::list <SDL_Window*> windowList;
};

#endif // WINDOW_MANAGER_H_


