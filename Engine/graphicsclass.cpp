////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	#pragma region Member
	m_D3D = 0;
	m_Camera = 0;	m_Camera_ = 0;
	m_TextureShader = 0;
	
	m_Dva1 = 0,	m_Dva2 = 0;	
	m_House1 = 0, m_House2 = 0, m_House3 = 0, m_House4 = 0, m_House5 = 0,
	m_tile1 = 0, m_tile2,
	m_flag1 = 0, m_flag2 = 0, m_flag3 = 0, m_flag4 = 0, m_flag5 = 0, m_flag6 = 0, m_flag7 = 0;
	m_board1 = 0, m_board2 = 0, 

	m_LightShader = 0;
	m_Light = 0;
	m_Light_ = 0;
	m_Bitmap = 0;
	m_Text = 0;
	#pragma endregion
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;
	D3DXMATRIX baseViewMatrix;

	#pragma region m_D3D

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}
	#pragma endregion

	#pragma region m_Camera
	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->GetViewMatrix(baseViewMatrix);

	m_Camera_ = new CameraClass;
	if (!m_Camera_)
	{
		return false;
	}
	// Set the initial position of the camera.
	m_Camera_->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera_->Render();
	m_Camera_->GetViewMatrix(baseViewMatrix);
	#pragma endregion

	#pragma region m_Text & m_TextShader
	// Create the text object.
	m_Text = new TextClass;
	if (!m_Text)
	{
		return false;
	}

	// Initialize the text object.
	result = m_Text->Initialize(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), hwnd, screenWidth, screenHeight, baseViewMatrix);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the text object.", L"Error", MB_OK);
		return false;
	}

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}
	#pragma endregion

	#pragma region m_Bitmap
	// Create the bitmap object.
	m_Bitmap = new BitmapClass;
	if (!m_Bitmap)
	{
		return false;
	}

	// Initialize the bitmap object.
	result = m_Bitmap->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight, L"../Engine/data/Texture/sky.dds", 1920, 1200);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bitmap object.", L"Error", MB_OK);
		return false;
	}
	#pragma endregion

	#pragma region m_Model

	// Create the model object.
	m_tile1 = new ModelClass;
	if (!m_tile1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_tile1->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/palm_island_OBJ_Island.obj", L"../Engine/data/Texture/sand.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_tile2 = new ModelClass;
	if (!m_tile2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_tile2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/palm_island_OBJ_Sea.obj", L"../Engine/data/Texture/sea.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	#pragma region Characters

	//// Create the model object.
	//m_Dva1 = new ModelClass;
	//if (!m_Dva1)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_Dva1->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/DVAt.obj", L"../Engine/data/Character/DVAt.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_Dva2 = new ModelClass;
	//if (!m_Dva2)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_Dva2->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/DVAb.obj", L"../Engine/data/Character/DVAb.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	#pragma endregion

	#pragma region House

	// Create the model object.
	m_House1 = new ModelClass;
	if (!m_House1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_House1->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/door.obj", L"../Engine/data/Texture/Future_Door_02_Ao.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_House2 = new ModelClass;
	if (!m_House2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_House2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/building_col_3.obj", L"../Engine/data/Texture/building_col_3.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_House3 = new ModelClass;
	if (!m_House3)
	{
		return false;
	}

	// Initialize the model object.
	result = m_House3->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/Glas_AO.obj", L"../Engine/data/Texture/Glas_AO.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_House4 = new ModelClass;
	if (!m_House4)
	{
		return false;
	}

	// Initialize the model object.
	result = m_House4->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/AussenWand_C.obj", L"../Engine/data/Texture/AussenWand_C.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_House5 = new ModelClass;
	if (!m_House5)
	{
		return false;
	}

	// Initialize the model object.
	result = m_House5->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/wallpaper.obj", L"../Engine/data/Texture/wallpaper.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	

	#pragma endregion

	#pragma region Board

	// Create the model object.
	m_board1 = new ModelClass;
	if (!m_board1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_board1->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/IKEABoard.obj", L"../Engine/data/Texture/IKEA.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_board2 = new ModelClass;
	if (!m_board2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_board2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/IKEABoardBone.obj", L"../Engine/data/Texture/iron.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	#pragma endregion
	
	#pragma region Flag

	//// Create the model object.
	//m_flag1 = new ModelClass;
	//if (!m_flag1)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag1->Initialize(m_D3D->GetDevice(), "../Engine/data/kit2.obj", L"../Engine/data/Bone.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_flag2 = new ModelClass;
	//if (!m_flag2)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag2->Initialize(m_D3D->GetDevice(), "../Engine/data/kit.obj", L"../Engine/data/Bone.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_flag3 = new ModelClass;
	//if (!m_flag3)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag3->Initialize(m_D3D->GetDevice(), "../Engine/data/flag.obj", L"../Engine/data/IKEA.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_flag4 = new ModelClass;
	//if (!m_flag4)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag4->Initialize(m_D3D->GetDevice(), "../Engine/data/flag.obj", L"../Engine/data/IKEA.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_flag5 = new ModelClass;
	//if (!m_flag5)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag5->Initialize(m_D3D->GetDevice(), "../Engine/data/flag.obj", L"../Engine/data/IKEA.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_flag6 = new ModelClass;
	//if (!m_flag6)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag6->Initialize(m_D3D->GetDevice(), "../Engine/data/kit3.obj", L"../Engine/data/Bone.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_flag7 = new ModelClass;
	//if (!m_flag7)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_flag7->Initialize(m_D3D->GetDevice(), "../Engine/data/TwoFloorRoom.obj", L"../Engine/data/Bone.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	#pragma endregion

	#pragma endregion

	#pragma region m_Light & LightShader
	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if (!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}


	
	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetAmbientColor(0.125f, 0.125f, 0.125f, 0.125f);
	m_Light->SetDiffuseColor(0.125f, 0.125f, 0.125f, 0.125f);
	m_Light->SetDirection(-15.0f, -10.0f, 15.0f);
	m_Light->SetSpecularColor(0.125f, 0.125f, 0.125f, 0.125f);
	m_Light->SetSpecularPower(850.0f);

	// Create the light object.
	m_Light_ = new LightClass;
	if (!m_Light_)
	{
		return false;
	}

	// Initialize the light object.
	m_Light_->SetAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(-35.0f, -30.0f, 15.0f);
	m_Light_->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_->SetSpecularPower(150.0f);

	#pragma endregion

	return true;
}


void GraphicsClass::Shutdown()
{
	#pragma region Shutdown

	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the light object.
	if (m_Light_)
	{
		delete m_Light_;
		m_Light_ = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the model object.
	if (m_Dva1)
	{
		m_Dva1->Shutdown();
		delete m_Dva1;
		m_Dva1 = 0;

		m_Dva2->Shutdown();
		delete m_Dva2;
		m_Dva2 = 0;
	}

	// Release the model object.
	if (m_tile1)
	{
		#pragma region Fixed

		m_tile1->Shutdown();
		delete m_tile1;
		m_tile1 = 0;

		m_tile2->Shutdown();
		delete m_tile2;
		m_tile2 = 0;

		m_House1->Shutdown();
		delete m_House1;
		m_House1 = 0;

		m_House2->Shutdown();
		delete m_House2;
		m_House2 = 0;

		m_House3->Shutdown();
		delete m_House3;
		m_House3 = 0;

		m_House4->Shutdown();
		delete m_House4;
		m_House4 = 0;

		m_House5->Shutdown();
		delete m_House5;
		m_House5 = 0;

		m_flag1->Shutdown();
		delete m_flag1;
		m_flag1 = 0;

		m_flag2->Shutdown();
		delete m_flag2;
		m_flag2 = 0;

		m_flag3->Shutdown();
		delete m_flag3;
		m_flag3 = 0;

		m_flag4->Shutdown();
		delete m_flag4;
		m_flag4 = 0;

		m_flag5->Shutdown();
		delete m_flag5;
		m_flag5 = 0;

		m_flag6->Shutdown();
		delete m_flag6;
		m_flag6 = 0;

		m_flag7->Shutdown();
		delete m_flag7;
		m_flag7 = 0;

		m_board1->Shutdown();
		delete m_board1;
		m_board1 = 0;

		m_board2->Shutdown();
		delete m_board2;
		m_board2 = 0;

		#pragma endregion
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	if (m_Camera_)
	{
		delete m_Camera_;
		m_Camera_ = 0;
	}

	// Release the D3D object.
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the bitmap object.
	if (m_Bitmap)
	{
		m_Bitmap->Shutdown();
		delete m_Bitmap;
		m_Bitmap = 0;
	}

	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the text object.
	if (m_Text)
	{
		m_Text->Shutdown();
		delete m_Text;
		m_Text = 0;
	}
	
	#pragma endregion
}

/*
	Frame 함수가 unity의 update함수와 같은 역할이라고 보면 됨.
	대부분의 반복되는 작업들이 대부분 이 안에 들어있음.
	인수가 조금 많지만, 카메라를 움직이게 하려면 어쩔수 없음
*/
bool GraphicsClass::Frame(int fps, int cpu, float frameTime, int mouseX, int mouseY, float left, float right, float front, float behind, float up, float down)
{
	bool result;

	#pragma region UI information
	// Set the location of the mouse.
	result = m_Text->SetMousePosition(mouseX, mouseY, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the frames per second.
	result = m_Text->SetFps(fps, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the cpu usage.
	result = m_Text->SetCpu(cpu, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	// Set the position of the camera.
	m_Camera->SetPosition(250.0f + left + right, 20.0f + up + down, -280.0f+ front + behind);
	
	// 마우스가 화면에 닿으면 안 움직이는 것은 정상임. 이건 따로 고칠 필요 없음.
	m_Camera->SetRotation((mouseY - 600) * 0.5f, (mouseX - 960) * 0.5f , 0.0f);	

	m_Camera_->SetPosition(0.0f, 0.0f, -10.0f);

	return true;
}

bool GraphicsClass::Render()
{
	D3DXMATRIX worldMatrix, viewMatrix, viewMatrix_, projectionMatrix, orthoMatrix, translate, scale;
	bool result;

	#pragma region rotation
	static float rotation = 0.0f;
	static float rotation_ = 0.0f;

	// Update the rotation variable each frame.
	rotation += (float)D3DX_PI * 0.002f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	rotation_ -= (float)D3DX_PI * 0.004f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	#pragma endregion

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();
	// for a bitmap
	m_Camera_->Render();

	// Get the view, projection, and world matrices from the camera and D3D objects.
	m_Camera->GetViewMatrix(viewMatrix);
	// for a bitmap
	m_Camera_->GetViewMatrix(viewMatrix_);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);
	m_D3D->GetOrthoMatrix(orthoMatrix);

	#pragma region 2DRendering

	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 0, 0);
	if (!result)
	{
		return false;
	}

	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap->GetIndexCount(), worldMatrix, viewMatrix_, orthoMatrix, m_Bitmap->GetTexture());
	if (!result)
	{
		return false;
	}

	// Turn on the alpha blending before rendering the text.
	m_D3D->TurnOnAlphaBlending();

	// Render the text strings.
	result = m_Text->Render(m_D3D->GetDeviceContext(), worldMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}

	// Turn off alpha blending after rendering the text.
	m_D3D->TurnOffAlphaBlending();

	// Turn the Z buffer back on now that all 2D rendering has completed.
	m_D3D->TurnZBufferOn();

	#pragma endregion
	
	#pragma region 3DRendering

	D3DXMATRIX worldMatrix_Tile;
	D3DXMatrixTranslation(&translate, 0.0f, -50.0f, 0.0f);
	D3DXMatrixScaling(&scale, 0.225f, 0.125f, 0.225f);
	worldMatrix_Tile = worldMatrix * translate * scale;
	m_tile1->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_tile1->GetIndexCount(), worldMatrix_Tile, viewMatrix, projectionMatrix,
		m_tile1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	
	D3DXMatrixTranslation(&translate, 0.0f, -70.0f, 0.0f);
	worldMatrix_Tile = worldMatrix * translate * scale;
	D3DXMatrixScaling(&scale, 3.25f, 2.25f, 3.25f);
	m_tile2->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_tile2->GetIndexCount(), worldMatrix_Tile, viewMatrix, projectionMatrix,
		m_tile2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	#pragma region Flag

	//D3DXMATRIX worldMatrix_flag1;
	//D3DXMatrixTranslation(&translate, 16.0f, 0.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 0.075f, 0.055f, 0.095f);
	//worldMatrix_flag1 = worldMatrix * scale * translate;
	//m_flag1->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag1->GetIndexCount(), worldMatrix_flag1, viewMatrix, projectionMatrix,
	//	m_flag1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_flag2;
	//D3DXMatrixTranslation(&translate, -16.0f, 0.0f, 0.0f);
	//worldMatrix_flag2 = worldMatrix * scale * translate;
	//m_flag2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag2->GetIndexCount(), worldMatrix_flag2, viewMatrix, projectionMatrix,
	//	m_flag2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_flag3;
	//D3DXMatrixTranslation(&translate, 16.0f, 0.0f, 20.0f);
	//worldMatrix_flag3 = worldMatrix * translate;
	//m_flag3->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag3->GetIndexCount(), worldMatrix_flag3, viewMatrix, projectionMatrix,
	//	m_flag3->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_flag4;
	//D3DXMatrixTranslation(&translate, 16.0f, 0.0f, -20.0f);
	//worldMatrix_flag4 = worldMatrix * translate;
	//m_flag4->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag4->GetIndexCount(), worldMatrix_flag4, viewMatrix, projectionMatrix,
	//	m_flag4->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_flag5;
	//D3DXMatrixTranslation(&translate, -16.0f, 0.0f, 20.0f);
	//worldMatrix_flag5 = worldMatrix * scale * translate;
	//m_flag5->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag5->GetIndexCount(), worldMatrix_flag5, viewMatrix, projectionMatrix,
	//	m_flag5->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_flag6;
	//D3DXMatrixTranslation(&translate, -16.0f, 0.0f, -20.0f);
	//worldMatrix_flag6 = worldMatrix* scale *translate;
	//m_flag6->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag6->GetIndexCount(), worldMatrix_flag6, viewMatrix, projectionMatrix,
	//	m_flag6->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_flag7;
	//D3DXMatrixTranslation(&translate, -16.0f, 11.125f, 25.0f);
	//D3DXMatrixScaling(&scale, 0.0055f, 0.0055f, 0.0055f);
	//worldMatrix_flag6 = worldMatrix * scale * translate;
	//m_flag7->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_flag7->GetIndexCount(), worldMatrix_flag6, viewMatrix, projectionMatrix,
	//	m_flag7->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}


	#pragma endregion

	#pragma region Build

	#pragma region House

	D3DXMATRIX worldMatrix_House;
	D3DXMatrixTranslation(&translate, 0.0f, 0.0f, 0.0f);
	D3DXMatrixScaling(&scale, 0.1f, 0.1f, 0.1f);
	worldMatrix_House = worldMatrix * translate * scale;
	
	m_House1->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_House1->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix,
		m_House1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_House2->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_House2->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix,
		m_House2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_House3->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_House3->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix,
		m_House3->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_House4->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_House4->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix,
		m_House4->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_House5->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_House5->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix,
		m_House5->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	
	
	#pragma endregion

	#pragma region Board

	D3DXMATRIX worldMatrix_Board;
	D3DXMatrixTranslation(&translate, -200.0f, 0.0f, -180.0f);
	D3DXMatrixScaling(&scale, 0.525f, 0.525f, 0.525f);
	D3DXMatrixRotationY(&worldMatrix, 230.0f);

	worldMatrix_Board = worldMatrix * translate * scale;
	m_board1->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_board1->GetIndexCount(), worldMatrix_Board, viewMatrix, projectionMatrix,
		m_board1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());

	worldMatrix_Board = worldMatrix * translate * scale;
	m_board2->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_board2->GetIndexCount(), worldMatrix_Board, viewMatrix, projectionMatrix,
		m_board2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());


	#pragma endregion

	#pragma endregion

	#pragma region Character

	#pragma region DVA

	//D3DXMATRIX worldMatrix_Dva;
	//D3DXMatrixTranslation(&translate, 0.0f, -130.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 0.0125f, 0.0125f, 0.0125f);	
	//D3DXMatrixRotationY(&worldMatrix, rotation);
	//worldMatrix_Dva = worldMatrix * translate * scale;
	//// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//m_Dva1->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Dva1->GetIndexCount(), worldMatrix_Dva, viewMatrix, projectionMatrix,
	//	m_Dva1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//m_Dva2->Render(m_D3D->GetDeviceContext());

	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Dva2->GetIndexCount(), worldMatrix_Dva, viewMatrix, projectionMatrix,
	//	m_Dva2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}


	#pragma endregion



	#pragma endregion




	#pragma endregion

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}
