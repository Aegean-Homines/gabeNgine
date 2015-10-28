#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_

#include <SDL_scancode.h>

class InputManager
{
public:
	static InputManager* getInputManagerInstance(void);
	bool isKeyDown(const char* key) const;
	bool isKeyDown(SDL_Scancode keyCode) const;
	bool isKeyUp(const char* key) const;
	//TODO figure out these two without creating another array
	bool isKeyReleased(const char* key) const;
	bool isKeyPressed(const char* key) const;
	void update();
private:
	static InputManager* instance;
	InputManager();
	InputManager(InputManager const&);
	InputManager& operator=(InputManager const&);
	~InputManager();
	bool pressedKeys[SDL_NUM_SCANCODES];
	bool previousKeys[SDL_NUM_SCANCODES];
};
#endif // INPUT_MANAGER_H_
