////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_TextureShader = 0;
	m_Model1 = 0;
	m_Model2 = 0;
	m_Model3 = 0;
	m_Model4 = 0;
	m_Model5 = 0;
	m_Model6 = 0;
	m_LightShader = 0;
	m_Light = 0;

	m_Bitmap = 0;
	m_Text = 0;
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

	// Create the model object.
	m_Model1 = new ModelClass;
	if (!m_Model1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model1->Initialize(m_D3D->GetDevice(), "../Engine/data/YrelSlaveOBJ.obj", L"../Engine/data/YrelSlaveOBJ.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model2 = new ModelClass;
	if (!m_Model2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model2->Initialize(m_D3D->GetDevice(), "../Engine/data/Aysa.obj", L"../Engine/data/Aysa.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model3 = new ModelClass;
	if (!m_Model3)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model3->Initialize(m_D3D->GetDevice(), "../Engine/data/FionaOBJ.obj", L"../Engine/data/FionaOBJ.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model4 = new ModelClass;
	if (!m_Model4)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model4->Initialize(m_D3D->GetDevice(), "../Engine/data/Baine.obj", L"../Engine/data/Baine.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model5 = new ModelClass;
	if (!m_Model5)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model5->Initialize(m_D3D->GetDevice(), "../Engine/data/Morticia-CrowleyOBJ.obj", L"../Engine/data/Morticia.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model6 = new ModelClass;
	if (!m_Model6)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model6->Initialize(m_D3D->GetDevice(), "../Engine/data/LowpingOBJ.obj", L"../Engine/data/LowpingOBJ.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

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
	m_Light->SetAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(0.35f, 0.35f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(60.0f);

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the model object.
	if (m_Model1)
	{
		m_Model1->Shutdown();
		delete m_Model1;
		m_Model1 = 0;
	}

	// Release the model object.
	if (m_Model2)
	{
		m_Model2->Shutdown();
		delete m_Model2;
		m_Model2 = 0;
	}

	// Release the model object.
	if (m_Model3)
	{
		m_Model3->Shutdown();
		delete m_Model3;
		m_Model3 = 0;
	}

	// Release the model object.
	if (m_Model4)
	{
		m_Model4->Shutdown();
		delete m_Model4;
		m_Model4 = 0;
	}

	// Release the model object.
	if (m_Model5)
	{
		m_Model5->Shutdown();
		delete m_Model5;
		m_Model5 = 0;
	}

	// Release the model object.
	if (m_Model6)
	{
		m_Model6->Shutdown();
		delete m_Model6;
		m_Model6 = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
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
}

bool GraphicsClass::Frame(int fps, int cpu, float frameTime, int mouseX, int mouseY, float left, float right, float front, float behind, float up, float down)
{
	bool result;

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

	// Set the position of the camera.
	m_Camera->SetPosition(left + right, up + down, -8.0f+ front + behind);
	m_Camera->SetRotation(((mouseY - 600)) * 0.95f,(mouseX - 960)* 0.95f, 0.0f);

	return true;
}

bool GraphicsClass::Render()
{
	D3DXMATRIX worldMatrix, localMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;

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

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.5f, 0.5f, 0.8f, 1.0f);

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 0, 0);
	if (!result)
	{
		return false;
	}
	// Generate the view matrix based on the camera's position.
	m_Camera->Render();
	
	// Get the view, projection, and world matrices from the camera and D3D objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);
	m_D3D->GetOrthoMatrix(orthoMatrix);

	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();


	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Bitmap->GetTexture());
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


	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationY(&worldMatrix, rotation);
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model1->Render(m_D3D->GetDeviceContext());


	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model1->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model1->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	
	D3DXMatrixRotationX(&worldMatrix, rotation);
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model2->Render(m_D3D->GetDeviceContext());


	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model2->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model2->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}


	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, rotation_);
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model3->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model3->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model3->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, rotation_);
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model4->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model4->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model4->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationX(&worldMatrix, rotation);
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model5->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model5->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model5->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationY(&worldMatrix, rotation_);
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model6->Render(m_D3D->GetDeviceContext());


	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model6->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model6->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}



	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}
