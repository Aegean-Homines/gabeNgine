#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include <list>

class sf::Window;

class WindowManager
{
public:

	//Creates window with a custom window title, if title = null creates one with default title
	sf::Window* CreateWindow(const char* windowTitle, int windowX, int windowY, int width, int height);
	sf::Window* CreateWindow(const char* windowTitle, int width, int height);
	static WindowManager* getWindowManagerInstance();
private:
	WindowManager();
	WindowManager(WindowManager const&);
	WindowManager& operator=(WindowManager const&);
	~WindowManager();
	static WindowManager* instance;
	std::list <sf::Window*> windowList;
};

#endif // WINDOW_MANAGER_H_


