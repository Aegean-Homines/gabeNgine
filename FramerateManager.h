#ifndef FRAMERATE_MANAGER_H_
#define FRAMERATE_MANAGER_H_

#include "SDL_stdinc.h"
#define MAX_FRAME_RATE 120

class FramerateManager
{
public:
	static FramerateManager* getFramerateManagerInstance(void);
	void frameStart(void);
	void frameEnd(void);
	Uint32 getFramerate() const { return framerate; }
	void setFramerate(Uint32 val);
private:
	Uint32 frameStartTime;
	Uint32 frameEndTime;
	Uint32 framerate;
	Uint32 timePerFrame;

	static FramerateManager* instance;
	FramerateManager();
	FramerateManager(FramerateManager const&);
	FramerateManager& operator=(FramerateManager const&);
	~FramerateManager();
};
#endif // FRAMERATE_MANAGER_H_