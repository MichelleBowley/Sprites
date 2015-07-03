#include "Main.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//{
//	WNDCLASSEX wndclass;
//	wndclass.cbSize = sizeof(WNDCLASSEX);
//	wndclass.style = CS_HREDRAW | CS_VREDRAW;
//	wndclass.lpfnWndProc = WndProc;
//	wndclass.cbClsExtra = 0;
//	wndclass.cbWndExtra = 0;
//	wndclass.hInstance = hInstance;
//	wndclass.hIcon = NULL;
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wndclass.lpszMenuName = NULL;
//	wndclass.lpszClassName = TITLE;
//	wndclass.hIconSm = NULL;
//
//	if (!RegisterClassEx(&wndclass))
//		return 0;
//
//	if (m_fullscreen) //if in m_fullscreen mode
//	{
//		hWindow = CreateWindowEx(0, TITLE, TITLE, WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP, 0, 0, screenWidth, screenHeight, NULL, NULL, hInstance, NULL);
//	}
//	else
//	{ //If in windwed mode
//		hWindow = CreateWindowEx(0, TITLE, TITLE, WS_OVERLAPPEDWINDOW,
//			screenWidth / 2 - (sWidth / 2), screenHeight / 2 - (sHeight / 2), sWidth, sHeight, NULL, NULL, hInstance, NULL);
//	}
//	ShowWindow(hWindow, iCmdShow);
//	UpdateWindow(hWindow);
//	
//	//dx = new DirectX;
//	//dx->InitDx(hWindow, screenWidth, screenHeight, m_fullscreen);
//	game = new Game;
//	game->Initialise(hWindow);
//
//	//m_background = new Sprite(0, 0);
//	//m_background->InitSprite(dx->d3d9_Device, "Sprites\\grass4.png", 1024, 1024);
//	//m_player1 = new Sprite(100, 100); //Makes a new player and adds the sprite in at 100, 100
//	//m_player1->InitSprite(dx->d3d9_Device, "Sprites\\BG.png", 865,  540); //TODO:: How to get my texture to stretch for the backgrund
//																			
//	
//	m_running = true;
//	while (m_running)
//	{
//		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//		{
//			if (msg.message == WM_QUIT) //If a quit message is recieved close down the application.
//			{
//				m_running = false;
//			}
//			else
//			{
//				TranslateMessage(&msg);
//				DispatchMessage(&msg);
//			}
//
//		}
//		game->Run();
//		/*Update(0.0f);
//		Draw(dx, 0.0f);*/
//	}
//	/*delete dx;
//	delete m_player1;
//	delete m_background;*/
//	return (int)msg.wParam;
//}
//
//
//LRESULT CALLBACK WndProc(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	/*return (game->messageHandler(hWindow, msg, wParam, lParam));
//}*/
//	switch (msg)
//	{
//	case WM_KEYDOWN:
//		switch (wParam)
//		{
//		case 0x1B:
//		{
//			int postQuitMsgBox = MessageBox(NULL, "Are you sure you want to quit?", "GoodBye", MB_YESNO | MB_ICONQUESTION | MB_TOPMOST);
//			switch (postQuitMsgBox)
//			{
//			case IDYES:
//				//If the yes button is selected then the application closes			
//				m_running = false;
//				break;
//			}
//			break;
//		}
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
//		return DefWindowProc(hWindow, msg, wParam, lParam);
//	}
//
//
//	//void Update(float gameTime)
//	//{
//	//	//update all game logic
//	//}
//	//void Draw(DirectX *dx, float gameTime)
//	//{
//	//	dx->Clear(D3DCOLOR_XRGB(0, 100, 100));
//	//	dx->Begin();
//	//
//	//	m_background->Draw(gameTime);
//	//	m_player1->Draw(gameTime);
//	//	
//	//
//	//	dx->End();
//	//	dx->PresentBB();
//	//}
//}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = NULL;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TITLE;
	wndclass.hIconSm = NULL;

	if (!RegisterClassEx(&wndclass))
		return 0;

	if (m_fullscreen) //if in m_fullscreen mode
	{
		hWindow = CreateWindowEx(0, TITLE, TITLE, WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP, 0, 0, screenWidth, screenHeight, NULL, NULL, hInstance, NULL);
	}
	else
	{ //If in windwed mode
		hWindow = CreateWindowEx(0, TITLE, TITLE, WS_OVERLAPPEDWINDOW,
			screenWidth / 2 - (sWidth / 2), screenHeight / 2 - (sHeight / 2), sWidth, sHeight, NULL, NULL, hInstance, NULL);
	}
	ShowWindow(hWindow, iCmdShow);
	UpdateWindow(hWindow);
	//game = new Game;
	game = new Game;
	game->Initialise(hWindow);
	//game->GameInit(hWindow); //Initialise the game includes directx initalisation too.
	m_running = true;
	while (m_running)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) //If a quit message is recieved close down the application.
			{
				m_running = false;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

		}
		game->Run();
		//game->Update(hWindow); //Update the game, every .....
		UpdateWindow(hWindow);
	}
	delete game;
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 0x1B:
		{
			int postQuitMsgBox = MessageBox(NULL, "Are you sure you want to quit?", "GoodBye", MB_YESNO | MB_ICONQUESTION | MB_TOPMOST);
			switch (postQuitMsgBox)
			{
			case IDYES:
				//If the yes button is selected then the application closes			
				m_running = false;
				break;
			}
			break;
		}
		case 122: //f12 part of debug. using f11 to toggle between fullscreen and windowed mode
			if (m_fullscreen)
			{
				m_fullscreen = false;
				SetWindowLong(hWindow, GWL_STYLE, WS_OVERLAPPEDWINDOW);
				SetWindowPos(hWindow, HWND_TOP, screenWidth / 2 - (sWidth / 2), screenHeight / 2 - (sHeight / 2), sWidth, sHeight, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
				RECT clientRect;
				GetClientRect(hWindow, &clientRect);
				MoveWindow(hWindow, screenWidth / 2 - (sWidth / 2), screenHeight / 2 - (sHeight / 2), sWidth, sHeight, TRUE);
			}
			else
			{
				m_fullscreen = true;
				SetWindowLong(hWindow, GWL_STYLE, WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP);
				SetWindowPos(hWindow, HWND_TOP, 0, 0, screenWidth, screenHeight, NULL);
			}
		}
		return 0;
		break;

	case WM_DESTROY:
		DestroyWindow(hWindow);
		m_running = false;
		PostQuitMessage(0);
		return 0;
		break;
	}
	return DefWindowProc(hWindow, msg, wParam, lParam);
}
