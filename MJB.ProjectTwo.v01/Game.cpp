#include "Game.h"

Game::Game()
{
	//input = new Input;
}

Game::~Game()
{
	/*int n = 0;

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
	}*/

	//TODO: delete each tile and set the pointer to null.
	
}

bool
Game::Initialise(HWND hWindow)  //HERE MARK
{
	dx = new DirectX; //Creates a new directx pointer

	if (!dx->InitDx(hWindow, screenWidth, screenHeight, m_fullscreen)) //Initialises directx and height and width and weather its fullscreen
	{
		return false;
	}

	//THIS IS THE BIT I NEED HELP WITH
	//I need to make a loop that adds a tile in and adds 100 to the width
	//int x = 0;

	//for (x = 0; x < 5; x++)
	//{
		
		while (y < sHeight)
		{
			x = 0;

			while (x < sWidth)
				//for (n = 0; n < 6; n++) 
			{

				tile1[n] = new GameObject(x, y, 0, 0, 0, 0);//This creates a new object for the tile, i think i need to dulicate this every loop

				x += tileWidth;

				if (!tile1[n]->Initialize(dx->d3d9_Device, "Sprites\\Tile1.png", tileWidth, tileHeight)) //This one just loads up the sprite from file using direct x
				{
					return false; //returns false if load failed
				}
				n++;
			}
			y += tileHeight;
		}

		
	//}
	
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
	
	int y = 0;

	while (y < sHeight)
	{
		int x = 0;
		while (x < sWidth)
			//for (n = 0; n <5 - 1; n++)
		{
			//for (n = 0; n < 6; n++)

			tile1[n]->Draw(gameTime);
			x += tileWidth;
			n++;
		}
		y += tileWidth;
	}
	//tile1[n]->Draw(gameTime);
	//TODO: Add a draw for each tile

	dx->End();
	dx->PresentBB();
}

void
Game::Update(float gameTime)
{
	//input->KeyboardInput();
	//input->MouseInput();


	int n = 0;
	
	int y = 0;
	while (y < sHeight)
	{
		int x = 0;

		while (x < sWidth)
			//for (n = 0; n < 5; n++)
		{
			//if (tile1[n])
			//{
		//for (n = 0; n < 6; n++)
			tile1[n]->Update(gameTime);
			x += tileWidth;
			//}
			//n++;
		}
		y += tileWidth;
	}

	//Tile1[n]->Update(gameTime);
	//Add a update for each tile
	
}

