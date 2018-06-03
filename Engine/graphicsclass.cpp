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
	
	m_Dva1 = 0;	m_Dva2 = 0;	
	m_Hanzo = 0;

	m_Boardsign = 0;	m_Furniture2 = 0;
	m_Tile = 0;			m_Staircase = 0;
	m_Sofa1 = 0;		m_Desk = 0;		
	m_chair05 = 0;		m_Wood_desk = 0;
	m_Lamp = 0;			m_woodStand = 0;
	m_Bench2 = 0;		m_computer_table = 0;

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
	result = m_Bitmap->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight, L"../Engine/data/aliance.dds", 1920, 1200);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bitmap object.", L"Error", MB_OK);
		return false;
	}
	#pragma endregion

	#pragma region m_Model
	// Create the model object.
	m_Dva1 = new ModelClass;
	if (!m_Dva1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Dva1->Initialize(m_D3D->GetDevice(), "../Engine/data/DVAt.obj", L"../Engine/data/DVAt.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Dva2 = new ModelClass;
	if (!m_Dva2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Dva2->Initialize(m_D3D->GetDevice(), "../Engine/data/DVAb.obj", L"../Engine/data/DVAb.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Hanzo = new ModelClass;
	if (!m_Hanzo)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Hanzo->Initialize(m_D3D->GetDevice(), "../Engine/data/Hanzo.obj", L"../Engine/data/Hanzo.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}







	//표지판
	m_Boardsign = new ModelClass;
	if (!m_Boardsign)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Boardsign->Initialize(m_D3D->GetDevice(), "../Engine/data/boardsign.obj", L"../Engine/data/boardsign.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}





	//타일 
	m_Tile = new ModelClass;
	if (!m_Tile)
	{
		return false;
	}

	result=m_Tile->Initialize(m_D3D->GetDevice(), "../Engine/data/tile.obj", L"../Engine/data/tile.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//가구,소파
	m_Sofa1 = new ModelClass;
	if (!m_Sofa1)
	{
		return false;
	}

	result = m_Sofa1->Initialize(m_D3D->GetDevice(), "../Engine/data/Canape.obj", L"../Engine/data/Canape.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//가구 의자
	m_chair05 = new ModelClass;
	if (!m_chair05)
	{
		return false;
	}

	result = m_chair05->Initialize(m_D3D->GetDevice(), "../Engine/data/chair05.obj", L"../Engine/data/chair05.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	//가구 벤치2
	m_Bench2 = new ModelClass;
	if (!m_Bench2)
	{
		return false;
	}

	result = m_Bench2->Initialize(m_D3D->GetDevice(), "../Engine/data/bench2.obj", L"../Engine/data/bench2.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	//가구 
	m_Furniture2 = new ModelClass;
	if (!m_Furniture2)
	{
		return false;
	}

	result = m_Furniture2->Initialize(m_D3D->GetDevice(), "../Engine/data/furniture2.obj", L"../Engine/data/iron2.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//전시장 2층공간
	m_Staircase = new ModelClass;
	if (!m_Staircase)
	{
		return false;
	}

	result = m_Staircase->Initialize(m_D3D->GetDevice(), "../Engine/data/Staircase.obj", L"../Engine/data/glass.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//램프
	m_Lamp = new ModelClass;
	if (!m_Lamp)
	{
		return false;
	}

	result = m_Lamp->Initialize(m_D3D->GetDevice(), "../Engine/data/lamp.obj", L"../Engine/data/lamp.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//책상
	m_Desk = new ModelClass;
	if (!m_Desk)
	{
		return false;
	}

	result = m_Desk->Initialize(m_D3D->GetDevice(), "../Engine/data/desk.obj", L"../Engine/data/desk.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	//나무책상
	m_Wood_desk = new ModelClass;
	if (!m_Wood_desk)
	{
		return false;
	}

	result = m_Wood_desk->Initialize(m_D3D->GetDevice(), "../Engine/data/woodDesk.obj", L"../Engine/data/woodDesk.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//화이트우드 서랍장
	m_woodStand = new ModelClass;
	if (!m_woodStand)
	{
		return false;
	}

	result = m_woodStand->Initialize(m_D3D->GetDevice(), "../Engine/data/Woodstand.obj", L"../Engine/data/Woodstand.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	//컴퓨터 테이블
	m_computer_table = new ModelClass;
	if (!m_computer_table)
	{
		return false;
	}

	result = m_computer_table->Initialize(m_D3D->GetDevice(), "../Engine/data/computerTable.obj", L"../Engine/data/computerTable.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


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
	if (m_Tile)
	{
		m_Tile->Shutdown();
		delete m_Tile;
		m_Tile = 0;
	}

	// Release the model object.
	if (m_Boardsign)
	{
		m_Boardsign->Shutdown();
		delete m_Boardsign;
		m_Boardsign = 0;
	}

	// Release the model object.
	if (m_Sofa1)
	{
		m_Sofa1->Shutdown();
		delete m_Sofa1;
		m_Sofa1 = 0;
	}

	// Release the model object.
	if (m_chair05)
	{
		m_chair05->Shutdown();
		delete m_chair05;
		m_chair05 = 0;
	}

	if (m_Furniture2)
	{
		m_Furniture2->Shutdown();
		delete m_Furniture2;
		m_Furniture2 = 0;
	}

	if (m_Staircase)
	{
		m_Staircase->Shutdown();
		delete m_Staircase;
		m_Staircase = 0;
	}

	if (m_Lamp)
	{
		m_Lamp->Shutdown();
		delete m_Lamp;
		m_Lamp = 0;
	}

	if (m_Desk)
	{
		m_Desk->Shutdown();
		delete m_Desk;
		m_Desk = 0;
	}

	if (m_Wood_desk)
	{
		m_Wood_desk->Shutdown();
		delete m_Wood_desk;
		m_Wood_desk = 0;
	}

	if (m_woodStand)
	{
		m_woodStand->Shutdown();
		delete m_woodStand;
		m_woodStand = 0;
	}

	if (m_computer_table)
	{
		m_computer_table->Shutdown();
		delete m_computer_table;
		m_computer_table = 0;
	}

	// Release the model object.
	if (m_Dva1)
	{
		m_Dva1->Shutdown();
		delete m_Dva1;
		m_Dva1 = 0;
	}

	// Release the model object.
	if (m_Dva2)
	{
		m_Dva2->Shutdown();
		delete m_Dva2;
		m_Dva2 = 0;
	}

	// Release the model object.
	if (m_Hanzo)
	{
		m_Hanzo->Shutdown();
		delete m_Hanzo;
		m_Hanzo = 0;
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
	m_Camera->SetPosition(left + right, up + down, -8.0f+ front + behind);
	
	// 마우스가 화면에 닿으면 안 움직이는 것은 정상임. 이건 따로 고칠 필요 없음.
	m_Camera->SetRotation((mouseY - 600) * 0.25f, (mouseX - 960) * 0.25f , 0.0f);	

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
	rotation += (float)D3DX_PI * 0.0002f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}
	rotation_ -= (float)D3DX_PI * 0.0004f;
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


#pragma region boardsign

	//표지판
	D3DXMATRIX worldMatrix_sign;
	D3DXMatrixTranslation(&translate, -11.5f, -5.0f, -10.0f);
	D3DXMatrixScaling(&scale, 0.3f, 0.3f, 0.3f);
	worldMatrix_sign = worldMatrix * translate * scale;

	m_Boardsign->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Boardsign->GetIndexCount(), worldMatrix_sign, viewMatrix, projectionMatrix,
		m_Boardsign->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion


#pragma region tile

	D3DXMATRIX worldMatrix_tile;
	D3DXMatrixTranslation(&translate, -11.5f, -12.5f, -5.0f);
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	worldMatrix_tile = worldMatrix * translate * scale;

	m_Tile->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Tile->GetIndexCount(), worldMatrix_tile, viewMatrix, projectionMatrix,
		m_Tile->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

#pragma region sofa1
	D3DXMATRIX worldMatrix_sofa1;
	D3DXMatrixTranslation(&translate, 4.0f, 0.0f, 4.0f);
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	worldMatrix_sofa1 = worldMatrix * translate * scale;

	m_Sofa1->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Sofa1->GetIndexCount(), worldMatrix_sofa1, viewMatrix, projectionMatrix,
		m_Sofa1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion


#pragma region chair05
	D3DXMATRIX worldMatrix_chair05;
	D3DXMatrixTranslation(&translate, -110.0f, 120.0f, -610.0f);
	D3DXMatrixScaling(&scale, 0.05f, 0.05f, 0.05f);
	worldMatrix_chair05 = worldMatrix * translate * scale;

	m_chair05->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_chair05->GetIndexCount(), worldMatrix_chair05, viewMatrix, projectionMatrix,
		m_chair05->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}



#pragma endregion

#pragma region Bench2

	D3DXMATRIX worldMatrix_Bench2;
	D3DXMatrixTranslation(&translate, -10.0f, -2.0f, -35.0f);
	D3DXMatrixScaling(&scale, 0.7f, 0.7f, 0.7f);
	worldMatrix_Bench2 = worldMatrix * translate * scale;

	m_Bench2->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Bench2->GetIndexCount(), worldMatrix_Bench2, viewMatrix, projectionMatrix,
		m_Bench2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion



#pragma region Furniture2

	D3DXMATRIX worldMatrix_Furniture2;
	D3DXMatrixTranslation(&translate, 4.0f, 100.0f, -1200.0f);
	D3DXMatrixScaling(&scale, 0.02f, 0.02f, 0.02f);
	worldMatrix_Furniture2 = worldMatrix * translate * scale;

	m_Furniture2->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Furniture2->GetIndexCount(), worldMatrix_Furniture2, viewMatrix, projectionMatrix,
		m_Furniture2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

#pragma region Staircase

	D3DXMATRIX worldMatrix_Staircase;
	D3DXMatrixTranslation(&translate, 4.0f, -7.0f, -100.0f);
	D3DXMatrixScaling(&scale, 0.50f, 0.30f, 0.30f);
	worldMatrix_Staircase = worldMatrix * translate * scale;

	m_Staircase->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Staircase->GetIndexCount(), worldMatrix_Staircase, viewMatrix, projectionMatrix,
		m_Staircase->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}
#pragma endregion

#pragma region Lamp

	D3DXMATRIX worldMatrix_Lamp;
	D3DXMatrixTranslation(&translate, 4.0f, 10.0f, -40.0f);
	D3DXMatrixScaling(&scale, 0.4f, 0.4f, 0.4f);
	worldMatrix_Lamp = worldMatrix * translate * scale;

	m_Lamp->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Lamp->GetIndexCount(), worldMatrix_Lamp, viewMatrix, projectionMatrix,
		m_Lamp->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion


#pragma region Desk

	D3DXMATRIX worldMatrix_Desk;
	D3DXMatrixTranslation(&translate, -4.0f, -0.5f, -10.0f);
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	worldMatrix_Desk = worldMatrix * translate * scale;

	m_Desk->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Desk->GetIndexCount(), worldMatrix_Desk, viewMatrix, projectionMatrix,
		m_Desk->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

#pragma region wood_desk

	D3DXMATRIX worldMatrix_Wood_desk;
	D3DXMatrixTranslation(&translate, 4.0f, -1.5f, -8.0f);
	D3DXMatrixScaling(&scale, 0.5f, 0.5f, 0.5f);
	worldMatrix_Wood_desk = worldMatrix * translate * scale;

	m_Wood_desk->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Wood_desk->GetIndexCount(), worldMatrix_Wood_desk, viewMatrix, projectionMatrix,
		m_Wood_desk->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

#pragma region woodStand

	D3DXMATRIX worldMatrix_Wood_stand;
	D3DXMatrixTranslation(&translate, -8.0f, 0.0f, -8.0f);
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	worldMatrix_Wood_stand = worldMatrix * translate * scale;

	m_woodStand->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_woodStand->GetIndexCount(), worldMatrix_Wood_stand, viewMatrix, projectionMatrix,
		m_woodStand->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

#pragma region computer_table

	D3DXMATRIX worldMatrix_computer_table;
	D3DXMatrixTranslation(&translate, -4.0f, 0.0f, -18.0f);
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	worldMatrix_computer_table = worldMatrix * translate * scale;

	m_computer_table->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_computer_table->GetIndexCount(), worldMatrix_computer_table, viewMatrix, projectionMatrix,
		m_computer_table->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion



	#pragma region DVA

	D3DXMATRIX worldMatrix_Dva;
	D3DXMatrixTranslation(&translate, -215.0f, -110.0f, 315.0f);
	D3DXMatrixScaling(&scale, 0.0125f, 0.0125f, 0.0125f);
	worldMatrix_Dva = worldMatrix * translate * scale;
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Dva1->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Dva1->GetIndexCount(), worldMatrix_Dva, viewMatrix, projectionMatrix,
		m_Dva1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Dva2->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Dva2->GetIndexCount(), worldMatrix_Dva, viewMatrix, projectionMatrix,
		m_Dva2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

	#pragma region Hanzo

	D3DXMATRIX worldMatrix_Hanzo;
	D3DXMatrixTranslation(&translate, 215.0f, -110.0f, 315.0f);
	D3DXMatrixScaling(&scale, 0.0125f, 0.0125f, 0.0125f);
	worldMatrix_Hanzo = worldMatrix * translate * scale;
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Hanzo->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Hanzo->GetIndexCount(), worldMatrix_Hanzo, viewMatrix, projectionMatrix,
		m_Hanzo->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion



#pragma endregion

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}
