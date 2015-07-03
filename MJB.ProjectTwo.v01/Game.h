#ifndef _GAME_H_
#define _GAME_H_

#include "DirectX.h"
#include "GameObject.h"
#include "Timer.h"

class Game
{
public:
	Game();
	~Game();

	bool Initialise(HWND hWindow);
	void Run();
	void Draw(float gameTime);
	void Update(float gameTime);

	static const int Max_Sprites = 100;

private:
	DirectX *dx;
	//GameObject *player;
	//GameObject *player2;


	GameObject *player3 [Max_Sprites];


	int screenWidth = GetSystemMetrics(SM_CXSCREEN); //Gets the width of the current monitor being used
	int screenHeight = GetSystemMetrics(SM_CYSCREEN); //Gets the height of the current monitor being used
	int sWidth = screenWidth - 150;
	int sHeight = screenHeight - 150;
	bool m_fullscreen;

	Timer *gameTime;
	//Input *input;

	bool m_running;


};

#endif //!_GAME_H_