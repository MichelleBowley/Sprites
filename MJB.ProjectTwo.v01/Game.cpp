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

	//TODO: delete each tile and set the pointer to null.
	
}

bool
Game::Initialise(HWND hWindow)
{
	dx = new DirectX;

	if (!dx->InitDx(hWindow, screenWidth, screenHeight, m_fullscreen))
	{
		return false;
	}

	int x = 0;
	//int y;
	int maxWidth = 5;

	//need to 
	/*Tile1 = new GameObject(x, y, 0, 0, 0, 0);
	if (!Tile1->Initialize(dx->d3d9_Device, "Sprites\\Tile1.png", 100, 100))*/
		//TODO: Make the tiles the background. 
	
	//TODO: Create a new gameobject for each tile and initialise 
	//TODO: Create a way of adding in the tiles reading from a text editor.
	//int n = 0;

	for (x = 0; x < 5; x++)
	{

		/*float RandomVelocityY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*5;
		float RandomVelocityX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)* 5;
		float RandomVelocity = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)* 5;
		double RandomStartx = rand() % (sWidth - 56) +10;
		double RandomStarty = rand() % (sHeight - 81) +10;*/
		//player3[n] = new GameObject(RandomStartx, RandomStarty, (float)M_PI_4, RandomVelocityY, RandomVelocityX, RandomVelocity);
		//if (!player3[n]->Initialize(dx->d3d9_Device, "Sprites\\p3.png", 32, 32)) //png format to use transcolour 255, 0, 255
		//{
		//	return false;
		//	//Make mouse a target, and shoot the sparites on screen. Every sprite clicked is then deleted from memory.
		//}
		int n = 0;
		for (n = 0; n < 5; n++)
		{
			n + 99;
			Tile1 = new GameObject(n, 0, 0, 0, 0, 0);
			if (!Tile1->Initialize(dx->d3d9_Device, "Sprites\\Tile1.png", 100, 100))
			{
			return false;
			}
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

	//int n = 0;

	//for (n = 0; n < Max_Sprites - 1; n++)
	//{
	//	player3[n]->Draw(gameTime);
	//}

	Tile1->Draw(gameTime);
	//TODO: Add a draw for each tile

	dx->End();
	dx->PresentBB();
}

void
Game::Update(float gameTime)
{
	//input->KeyboardInput();
	//input->MouseInput();


	/*int n = 0;

	for (n = 0; n < Max_Sprites - 1; n++)
	{
		if (player3[n])
		{
			player3[n]->Update(gameTime);
		}
	}
*/
	Tile1->Update(gameTime);
	//Add a update for each tile
	
}

