////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "inputclass.h"


InputClass::InputClass()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;
}


InputClass::InputClass(const InputClass& other)
{
}


InputClass::~InputClass()
{
}


bool InputClass::Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	HRESULT result;


	// Store the screen size which will be used for positioning the mouse cursor.
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	// Initialize the location of the mouse on the screen.
	m_mouseX = 872;
	m_mouseY = 600;

	// Initialize the main direct input interface.
	result = DirectInput8Create(hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the keyboard.
	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format.  In this case since it is a keyboard we can use the predefined data format.
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
	{
		return false;
	}

	// Set the cooperative level of the keyboard to share with other programs.
	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Now acquire the keyboard.
	result = m_keyboard->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the mouse.
	result = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format for the mouse using the pre-defined mouse data format.
	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
	{
		return false;
	}

	// Set the cooperative level of the mouse to share with other programs.
	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Acquire the mouse.
	result = m_mouse->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	return true;
}


void InputClass::Shutdown()
{
	// Release the mouse.
	if (m_mouse)
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	// Release the keyboard.
	if (m_keyboard)
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	// Release the main interface to direct input.
	if (m_directInput)
	{
		m_directInput->Release();
		m_directInput = 0;
	}

	return;
}


bool InputClass::Frame()
{
	bool result;


	// Read the current state of the keyboard.
	result = ReadKeyboard();
	if (!result)
	{
		return false;
	}

	// Read the current state of the mouse.
	result = ReadMouse();
	if (!result)
	{
		return false;
	}

	// Process the changes in the mouse and keyboard.
	ProcessInput();

	return true;
}


bool InputClass::ReadKeyboard()
{
	HRESULT result;


	// Read the keyboard device.
	result = m_keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);
	if (FAILED(result))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_keyboard->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}


bool InputClass::ReadMouse()
{
	HRESULT result;


	// Read the mouse device.
	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	if (FAILED(result))
	{
		// If the mouse lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_mouse->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}


void InputClass::ProcessInput()
{
	// Update the location of the mouse cursor based on the change of the mouse location during the frame.
	m_mouseX += m_mouseState.lX;
	m_mouseY += m_mouseState.lY;

	// Ensure the mouse location doesn't exceed the screen width or height.
	if (m_mouseX < 0) { m_mouseX = 0; }
	if (m_mouseY < 0) { m_mouseY = 0; }

	if (m_mouseX > m_screenWidth) { m_mouseX = m_screenWidth; }
	if (m_mouseY > m_screenHeight) { m_mouseY = m_screenHeight; }

return;
}


bool InputClass::IsEscapePressed()
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_ESCAPE] & 0x80)
	{
		return true;
	}

	return false;
}

void InputClass::CameraMoveL(float& move)
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_A] & 0x80)
	{
		move -= 0.125f;
	}
}

void InputClass::CameraMoveR(float& move)
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_D] & 0x80)
	{
		move += 0.125f;
	}
}

void InputClass::CameraMoveU(float& move)
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_W] & 0x80)
	{
		move += 0.125f;
	}
}
void InputClass::CameraMoveD(float& move)
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_S] & 0x80)
	{
		move -= 0.125f;
	}
}

void InputClass::CameraMoveF(float& move)
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_E] & 0x80)
	{
		move += 0.125f;
	}
}

void InputClass::CameraMoveB(float& move)
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_Q] & 0x80)
	{
		move -= 0.125f;
	}
}


// This Function Must need the Fullscreen
void InputClass::CameraMoveForRoom(float& left, float& right, float& front, float& behind, float& up, float& down)
{
	// (-188, 28, 203) 841, 630
	if (m_keyboardState[DIK_1] & 0x80)
	{
		// -188
		// x축 좌표가 -188보다 작으면, 커질때까지 더해준다.
	
		#pragma region KeyBoardSet

		left = -188;
		right = 0;
		front = 203;
		behind = 0;
		up = 28;
		down = 0;


		//if ((left + right) < -188.0f)
		//{
		//	while ((left + right) >= -188.0f)
		//	{
		//		right += 0.125f;
		//	}
		//}

		//// 그렇지 않으면 작아질 때까지 빼준다.
		//else if ((left + right) > -188.0f)
		//{
		//	while ((left + right) <= -188.0f)
		//	{
		//		left -= 0.125f;
		//	}
		//}

		//// 28
		//if ((up + down) < 28.0f)
		//{
		//	while ((up + down) >= 28.0f)
		//	{
		//		up += 0.125f;
		//	}
		//}

		//else if ((up + down) > 28.0f)
		//{
		//	while ((up + down) <= 28.0f)
		//	{
		//		down -= 0.125f;
		//	}
		//}

		//// 203
		//if ((front + behind) < 203.0f)
		//{
		//	while ((front + behind) >= 203.0f)
		//	{
		//		front += 0.125f;
		//	}
		//}

		//else if ((front + behind) > 203.0f)
		//{
		//	while ((front + behind) <= 203.0f)
		//	{
		//		behind -= 0.125f;
		//	}
		//}

		#pragma endregion

		m_mouseX = 841;
		m_mouseY = 630;
	}

	// (-232, 30, 240) 1030, 635
	if (m_keyboardState[DIK_2] & 0x80)
	{
		left = -232;
		right = 0;
		front = 240;
		behind = 0;
		up = 30;
		down = 0;

		m_mouseX = 1030;
		m_mouseY = 635;
	}

	// (-339, 60, 185) 1049, 617
	if (m_keyboardState[DIK_3] & 0x80)
	{
		left = -339;
		right = 0;
		front = 185;
		behind = 0;
		up = 60;
		down = 0;

		m_mouseX = 1049;
		m_mouseY = 617;
	}

	// (-350, 27, 375) 1161, 619
	if (m_keyboardState[DIK_4] & 0x80)
	{
		left = -350;
		right = 0;
		front = 375;
		behind = 0;
		up = 27;
		down = 0;

		m_mouseX = 1161;
		m_mouseY = 619;
	}

	// (-315, 25, 345) 511, 634
	if (m_keyboardState[DIK_5] & 0x80)
	{
		left = -315;
		right = 0;
		front = 345;
		behind = 0;
		up = 25;
		down = 0;

		m_mouseX = 511;
		m_mouseY = 634;
	}

	// (-326,  308, -133) 981, 652
	if (m_keyboardState[DIK_6] & 0x80)
	{
		left = -326;
		right = 0;
		front = 0;
		behind = -133;
		up = 308;
		down = 0;

		m_mouseX = 981;
		m_mouseY = 652;
	}
}

void InputClass::BitmapMove(float& move)
{
	if (m_keyboardState[DIK_Z] & 0x80)
	{
		move = -2000;
	}

	if (m_keyboardState[DIK_X] & 0x80)
	{
		move = 0;
	}
}

void InputClass::ObjectMove(bool& moved)
{
	if (m_keyboardState[DIK_O] & 0x80)
	{
		moved = TRUE;
	}
	if (m_keyboardState[DIK_P] & 0x80)
	{
		moved = FALSE;
		m_mouseX = 960;
		m_mouseY = 600;
	}
}

bool InputClass::CameraFixed()
{
	if (m_keyboardState[DIK_SPACE] & 0x80)
	{
		m_mouseX = 872;
		m_mouseY = 600;
		return TRUE;
	}
	else
		return FALSE;
}

void InputClass::GetMouseLocation(int& mouseX, int& mouseY)
{
	mouseX = m_mouseX;
	mouseY = m_mouseY;
	return;
}

