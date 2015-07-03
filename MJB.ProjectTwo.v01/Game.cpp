#include "Game.h"

Game::Game()
{
	//input = new Input;
}

Game::~Game()
{
	int n = 0;

	for (n = 0; n < Max_Sprites - 1; n++)
	{

		if (player3[n])
		{
			delete player3[n];
			player3[n] = 0;
		}
	}
	
	if (dx)
	{
		delete dx;
		dx = 0;
	}
	/*if (input)
	{
		delete input;
		input = 0;
	}*/
}

bool
Game::Initialise(HWND hWindow)
{
	//double RandomStartX
	//double RandomStartY
	//double RandomVelocity = rand() % 10 + 1;
	//double RandomVeloctyY = rand() % 10 + 1;
	dx = new DirectX;

	if (!dx->InitDx(hWindow, screenWidth, screenHeight, m_fullscreen))
	{
		return false;
	}
	int n = 0;

	for (n = 0; n < Max_Sprites -1; n++)
	{
		float RandomVelocityY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*5;
		float RandomVelocityX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)* 5;
		float RandomVelocity = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)* 5;
		double RandomStartx = rand() % (sWidth - 56) +10;
		double RandomStarty = rand() % (sHeight - 81) +10;
		player3[n] = new GameObject(RandomStartx, RandomStarty, (float)M_PI_4, RandomVelocityY, RandomVelocityX, RandomVelocity);
		if (!player3[n]->Initialize(dx->d3d9_Device, "Sprites\\p3.png", 32, 32)) //png format to use transcolour 255, 0, 255
		{
			return false;
			//Make mouse a target, and shoot the sparites on screen. Every sprite clicked is then deleted from memory.
		}

	}
	
	gameTime = new Timer;
	if (!gameTime->Initialise())
	{
		return false;
	}
	m_running = true;
	return true;
}

void
Game::Run()
{
	gameTime->Update();

	Update(gameTime->elapsedTime);
	Draw(gameTime->elapsedTime);
}

void
Game::Draw(float gameTime)
{
	dx->Clear(D3DCOLOR_XRGB(0, 100, 100));
	dx->Begin();

	int n = 0;

	for (n = 0; n < Max_Sprites - 1; n++)
	{
		player3[n]->Draw(gameTime);
	}


	dx->End();
	dx->PresentBB();
}

void
Game::Update(float gameTime)
{
	//input->KeyboardInput();
	//input->MouseInput();


	int n = 0;

	for (n = 0; n < Max_Sprites - 1; n++)
	{
		if (player3[n])
		{
			player3[n]->Update(gameTime);
		}
	}
	
}

//LRESULT Game::messageHandler(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	if (m_running)
//	{
//		switch (msg)
//		{
//		case 122: //f12 part of debug. using f11 to toggle between fullscreen and windowed mode
//			if (m_fullscreen)
//			{
//				m_fullscreen = false;
//				SetWindowLong(hWindow, GWL_STYLE, WS_OVERLAPPEDWINDOW);
//				SetWindowPos(hWindow, HWND_TOP, screenWidth / 2 - (sWidth / 2), screenHeight / 2 - (sHeight / 2), sWidth, sHeight, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
//				RECT clientRect;
//				GetClientRect(hWindow, &clientRect);
//				MoveWindow(hWindow, screenWidth / 2 - (sWidth / 2), screenHeight / 2 - (sHeight / 2), sWidth, sHeight, TRUE);
//			}
//			else
//			{
//				m_fullscreen = true;
//				SetWindowLong(hWindow, GWL_STYLE, WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP);
//				SetWindowPos(hWindow, HWND_TOP, 0, 0, screenWidth, screenHeight, NULL);
//			}
//			return 0;
//			break;
//
//		case WM_DESTROY:
//			DestroyWindow(hWindow);
//			m_running = false;
//			PostQuitMessage(0);
//			return 0;
//			break;
//		}
//		return DefWindowProc(hWindow, msg, wParam, lParam);    // let Windows handle it
//	}
//}
