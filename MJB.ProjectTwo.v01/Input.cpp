//#include "Input.h"
//
//Input::Input()
//{
//}
//
//Input::~Input()
//{
//}
//
//void
//Input::MouseInput()
//{
//	//Have a message handle for the left mouse button
//	if (GetAsyncKeyState(MK_LBUTTON))
//	{
//		POINT p;
//		GetCursorPos(&p);
//
//		int mouseX = p.x;
//		
//		int mouseY = p.y;
//
//	
//
//		std::string message = "Left mouse button was pressed \n x =" + std::to_string(mouseX)+"\n y = " + std::to_string(mouseY);
//
//		MessageBox(NULL, message.c_str() ,NULL, NULL);
//		
//		//Need a way to add co ordinates to the message box!!
//	}
//}
//
//void 
//Input::KeyboardInput()
//{
//	if (GetAsyncKeyState(VK_ESCAPE))
//	{
//	int postQuitMsgBox = MessageBox(NULL, "Are you sure you want to quit?", "GoodBye", MB_YESNO | MB_ICONQUESTION | MB_TOPMOST);
//	switch (postQuitMsgBox)
//	{
//	case IDYES:
//		//If the yes button is selected then the application closes			
//		PostQuitMessage(0);
//		break;
//	}
//
//
//if (GetAsyncKeyState(67))//c key
//{
//	std::string message = "c was pressed";
//	MessageBox(NULL, message.c_str(), NULL, NULL);
//}
//	}
//}
