////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	#pragma region Member
	
	m_D3D = 0;
	m_Camera = 0;	m_Camera_ = 0;	m_Camera__;
	m_TextureShader = 0;
	
	#pragma region m_Model
	
	//캐릭터
	m_lego1 = 0, m_lego2 = 0;	m_Carobj = 0;
	m_Dva1 = 0, m_Dva2 = 0;
	m_storm_trooper = 0;
	m_space_marine = 0;
	m_nomad = 0;
	m_worker = 0;
	m_Droid = 0;
	m_bloodwing = 0;

	//이케아
	m_House1 = 0, m_House2 = 0, m_House3 = 0, m_House4 = 0, m_House5 = 0,
	m_tile1 = 0, m_tile2,

	m_board1 = 0, m_board2 = 0,

	//날아다니는 비행체
	m_UFO = 0;
	
	//가구
	m_Sofa1 = 0;	m_Sofa2 = 0;
	m_Bench2 = 0;
	m_Desk = 0;
	m_Wood_desk = 0;
	m_chair05 = 0;		m_chair01 = 0;
	m_Table_Chair01 = 0;
	m_Table_Chair02 = 0;

	m_Furniture2 = 0;
	m_sign01 = 0;

	m_wooden_sofa1 = 0;	m_wooden_sofa2 = 0;	m_wooden_sofa3 = 0;	m_wooden_sofa4 = 0;	m_wooden_sofa5 = 0;	m_wooden_sofa6 = 0;
	m_wooden_sofa7 = 0; m_wooden_sofa8 = 0;

	m_woodStand = 0;

	//자동차
	m_car = 0;
	m_car2 = 0;
	
	#pragma endregion

	m_LightShader = 0;
	m_Light = 0;
	m_Light_ = 0;
	m_Light__ = 0;
	m_Bitmap = 0;	m_Bitmap2 = 0;
	m_Text = 0;
	m_BumpMapShader = 0;
	m_GlassShader = 0;
	m_RenderTexture = 0;

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

	m_Camera__ = new CameraClass;
	if (!m_Camera__)
	{
		return false;
	}
	// Set the initial position of the camera.
	m_Camera__->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera__->Render();
	m_Camera__->GetViewMatrix(baseViewMatrix);

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

	// Create the bitmap object.
	m_Bitmap2 = new BitmapClass;
	if (!m_Bitmap2)
	{
		return false;
	}

	// Initialize the bitmap object.
	result = m_Bitmap2->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight, L"../Engine/data/Texture/night.dds", 1920, 1200);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bitmap object.", L"Error", MB_OK);
		return false;
	}



	#pragma endregion
	
	//#pragma region m_Model

	//// Create the model object.
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

	//#pragma region Characters

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

	////// Create the model object.
	////m_Dva2 = new ModelClass;
	////if (!m_Dva2)
	////{
	////	return false;
	////}

	////// Initialize the model object.
	////result = m_Dva2->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/DVAb.obj", L"../Engine/data/Character/DVAb.dds");
	////if (!result)
	////{
	////	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	////	return false;
	////}

	// Create the model object.
	m_lego1 = new ModelClass;
	if (!m_lego1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_lego1->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/lego_head.obj", L"../Engine/data/Texture/LegoFace.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_lego2 = new ModelClass;
	if (!m_lego2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_lego2->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/lego_body.obj", L"../Engine/data/Texture/LegoBody.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	// Create the model object.
	m_Carobj = new ModelClass;
	if (!m_Carobj)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Carobj->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/Lamborghini.obj", L"../Engine/data/Texture/Lamborginhi.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	//// Create the model object.
	//m_storm_trooper = new ModelClass;
	//if (!m_storm_trooper)
	//{
	//	return false;
	//}

	////Initialize the model object.
	//result = m_storm_trooper->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/StormTrooper.obj", L"../Engine/data/Texture/StormTrooper.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//m_space_marine = new ModelClass;
	//if (!m_space_marine)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_space_marine->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/spacemarine.obj", L"../Engine/data/Texture/spacemarine.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//m_nomad = new ModelClass;
	//if (!m_nomad)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_nomad->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/Nomad.obj", L"../Engine/data/Texture/Nomad.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//m_worker = new ModelClass;
	//if (!m_worker)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_worker->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/HyperionWorker.obj", L"../Engine/data/Texture/HyperionWorker.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//m_Droid = new ModelClass;
	//if (!m_Droid)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_Droid->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/BattleDroid.obj", L"../Engine/data/Texture/BattleDroid.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//m_bloodwing = new ModelClass;
	//if (!m_bloodwing)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_bloodwing->Initialize(m_D3D->GetDevice(), "../Engine/data/Character/Bloodwing.obj", L"../Engine/data/Texture/Bloodwing.dds");
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

	#pragma region Build

	////가구,소파
	//m_Sofa1 = new ModelClass;
	//if (!m_Sofa1)
	//{
	//	return false;
	//}

	//result = m_Sofa1->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/Canape.obj", L"../Engine/data/Texture/Canape.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////가구,소파
	//m_Sofa2 = new ModelClass;
	//if (!m_Sofa2)
	//{
	//	return false;
	//}

	//result = m_Sofa2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/Canape.obj", L"../Engine/data/Texture/Canape2.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////가구 벤치2

	//m_Bench2 = new ModelClass;
	//if (!m_Bench2)
	//{
	//	return false;
	//}

	//result = m_Bench2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/bench2.obj", L"../Engine/data/Texture/bench2.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////책상
	//m_Desk = new ModelClass;
	//if (!m_Desk)
	//{
	//	return false;
	//}

	//result = m_Desk->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/desk.obj", L"../Engine/data/Texture/desk.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////나무책상
	//m_Wood_desk = new ModelClass;
	//if (!m_Wood_desk)
	//{
	//	return false;
	//}

	//result = m_Wood_desk->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/woodDesk.obj", L"../Engine/data/Texture/woodDesk.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////의자
	//m_chair05 = new ModelClass;
	//if (!m_chair05)
	//{
	//	return false;
	//}

	//result = m_chair05->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/chair05.obj", L"../Engine/data/Texture/chair05.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////의자
	//m_chair01 = new ModelClass;
	//if (!m_chair01)
	//{
	//	return false;
	//}

	//result = m_chair01->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/chair01.obj", L"../Engine/data/Texture/chair01.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////테이블체어
	//m_Table_Chair01 = new ModelClass;
	//if (!m_Table_Chair01)
	//{
	//	return false;
	//}

	//result = m_Table_Chair01->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/TableChair01.obj", L"../Engine/data/Texture/TableChair01.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////테이블체어
	//m_Table_Chair02 = new ModelClass;
	//if (!m_Table_Chair02)
	//{
	//	return false;
	//}

	//result = m_Table_Chair02->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/TableChair02.obj", L"../Engine/data/Texture/TableChair02.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////가구
	//m_Furniture2 = new ModelClass;
	//if (!m_Furniture2)
	//{
	//	return false;
	//}

	//result = m_Furniture2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/furniture2.obj", L"../Engine/data/Texture/furniture2.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa1 = new ModelClass;
	//if (!m_wooden_sofa1)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa1->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa.obj", L"../Engine/data/Texture/WoodenSofa.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa2 = new ModelClass;
	//if (!m_wooden_sofa2)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa2.obj", L"../Engine/data/Texture/WoodenSofa2.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa3 = new ModelClass;
	//if (!m_wooden_sofa3)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa3->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa.obj", L"../Engine/data/Texture/WoodenSofa3.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa4 = new ModelClass;
	//if (!m_wooden_sofa4)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa4->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa2.obj", L"../Engine/data/Texture/WoodenSofa4.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa5 = new ModelClass;
	//if (!m_wooden_sofa5)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa5->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa.obj", L"../Engine/data/Texture/WoodenSofa5.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa6 = new ModelClass;
	//if (!m_wooden_sofa6)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa6->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa2.obj", L"../Engine/data/Texture/WoodenSofa6.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa7 = new ModelClass;
	//if (!m_wooden_sofa7)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa7->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa.obj", L"../Engine/data/Texture/WoodenSofa7.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_wooden_sofa8 = new ModelClass;
	//if (!m_wooden_sofa8)
	//{
	//	return false;
	//}

	//result = m_wooden_sofa8->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/WoodenSofa2.obj", L"../Engine/data/Texture/WoodenSofa8.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	////소파
	//m_woodStand = new ModelClass;
	//if (!m_woodStand)
	//{
	//	return false;
	//}

	//result = m_woodStand->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/Woodstand.obj", L"../Engine/data/Texture/Woodstand.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}
	
	#pragma endregion

	#pragma region UFO
	
	m_UFO = new ModelClass;
	if (!m_UFO)
	{
		return false;
	}

	// Initialize the model object.
	result = m_UFO->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/flyingDiskflying.obj", L"../Engine/data/Texture/flyingDiskflying.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
	
	#pragma endregion
	
	#pragma region Car
	
	//m_car = new ModelClass;
	//if (!m_car)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_car->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/car1.obj", L"../Engine/data/Texture/car1.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//m_car2 = new ModelClass;
	//if (!m_car2)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_car2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/car2.obj", L"../Engine/data/Texture/car2.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}
	
	#pragma endregion

	#pragma region Board

	//m_sign01 = new ModelClass;
	//if (!m_sign01)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_sign01->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/sign01.obj", L"../Engine/data/Texture/sign01.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_board1 = new ModelClass;
	//if (!m_board1)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_board1->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/IKEABoard.obj", L"../Engine/data/Texture/IKEA.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create the model object.
	//m_board2 = new ModelClass;
	//if (!m_board2)
	//{
	//	return false;
	//}

	//// Initialize the model object.
	//result = m_board2->Initialize(m_D3D->GetDevice(), "../Engine/data/Build/IKEABoardBone.obj", L"../Engine/data/Texture/iron.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	#pragma endregion

	//#pragma endregion

	#pragma region bumpermap

	// Create the bump map shader object.
	m_BumpMapShader = new BumpMapShaderClass;
	if (!m_BumpMapShader)
	{
		return false;
	}

	// Initialize the bump map shader object.
	result = m_BumpMapShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bump map shader object.", L"Error", MB_OK);
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
	m_Light->SetAmbientColor(0.825f, 0.825f, 1.0f, 1.0f);
	m_Light->SetDiffuseColor(0.8f, 0.8f, 1.0f, 1.0f);
	m_Light->SetDirection(0.0f, 0.0f, 0.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
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
	m_Light_->SetDirection(-50.0f, 50.0f, 50.0f);
	m_Light_->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_->SetSpecularPower(150.0f);

	// Create the light object.
	m_Light__ = new LightClass;
	if (!m_Light__)
	{
		return false;
	}

	// Initialize the light object.
	m_Light__->SetAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light__->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light__->SetDirection(-35.0f, -30.0f, 15.0f);
	
	m_Light__->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light__->SetSpecularPower(150.0f);

	#pragma endregion

	#pragma region RefractionTexture

	// Create the render to texture object.
	m_RenderTexture = new RenderTextureClass;
	if (!m_RenderTexture)
	{
		return false;
	}

	// Initialize the render to texture object.
	result = m_RenderTexture->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight);
	if (!result)
	{
		return false;
	}

	// Create the glass shader object.
	m_GlassShader = new GlassShaderClass;
	if (!m_GlassShader)
	{
		return false;
	}

	// Initialize the glass shader object.
	result = m_GlassShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the glass shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the refraction render to texture object.
	m_RefractionTexture = new RenderTextureClass;
	if (!m_RefractionTexture)
	{
		return false;
	}

	// Initialize the refraction render to texture object.
	result = m_RefractionTexture->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the refraction render to texture object.", L"Error", MB_OK);
		return false;
	}

	// Create the reflection render to texture object.
	m_ReflectionTexture = new RenderTextureClass;
	if (!m_ReflectionTexture)
	{
		return false;
	}

	// Initialize the reflection render to texture object.
	result = m_ReflectionTexture->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the reflection render to texture object.", L"Error", MB_OK);
		return false;
	}

	// Create the refraction shader object.
	m_RefractionShader = new RefractionShaderClass;
	if (!m_RefractionShader)
	{
		return false;
	}

	// Initialize the refraction shader object.
	result = m_RefractionShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the refraction shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the water shader object.
	m_WaterShader = new WaterShaderClass;
	if (!m_WaterShader)
	{
		return false;
	}

	// Initialize the water shader object.
	result = m_WaterShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the water shader object.", L"Error", MB_OK);
		return false;
	}

	// Set the height of the water.
	m_waterHeight = 2.75f;

	// Initialize the position of the water.
	m_waterTranslation = 0.0f;



	#pragma endregion
	
	return true;
}


void GraphicsClass::Shutdown()
{
	#pragma region Shutdown

	// Release the glass shader object.
	if (m_GlassShader)
	{
		m_GlassShader->Shutdown();
		delete m_GlassShader;
		m_GlassShader = 0;
	}

	// Release the render to texture object.
	if (m_RenderTexture)
	{
		m_RenderTexture->Shutdown();
		delete m_RenderTexture;
		m_RenderTexture = 0;
	}

	// Release the water shader object.
	if (m_WaterShader)
	{
		m_WaterShader->Shutdown();
		delete m_WaterShader;
		m_WaterShader = 0;
	}

	// Release the refraction shader object.
	if (m_RefractionShader)
	{
		m_RefractionShader->Shutdown();
		delete m_RefractionShader;
		m_RefractionShader = 0;
	}

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

	// Release the bump map shader object.
	if (m_BumpMapShader)
	{
		m_BumpMapShader->Shutdown();
		delete m_BumpMapShader;
		m_BumpMapShader = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the reflection render to texture object.
	if (m_ReflectionTexture)
	{
		m_ReflectionTexture->Shutdown();
		delete m_ReflectionTexture;
		m_ReflectionTexture = 0;
	}

	// Release the refraction render to texture object.
	if (m_RefractionTexture)
	{
		m_RefractionTexture->Shutdown();
		delete m_RefractionTexture;
		m_RefractionTexture = 0;
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

		delete m_Camera__;
		m_Camera__ = 0;
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

		m_Bitmap2->Shutdown();
		delete m_Bitmap2;
		m_Bitmap2 = 0;
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

	#pragma region m_Model

	// Release the model object.
	if (m_Dva1)
	{
		m_Dva1->Shutdown();
		delete m_Dva1;
		m_Dva1 = 0;

		m_Dva2->Shutdown();
		delete m_Dva2;
		m_Dva2 = 0;

		m_lego1->Shutdown();
		delete m_lego1;
		m_lego1 = 0;

		m_lego2->Shutdown();
		delete m_lego2;
		m_lego2 = 0;
	}

	if (m_storm_trooper)
	{
		m_Carobj->Shutdown();
		delete m_Carobj;
		m_Carobj = 0;

		m_storm_trooper->Shutdown();
		delete m_storm_trooper;
		m_storm_trooper = 0;
	}


	if (m_space_marine)
	{
		m_space_marine->Shutdown();
		delete m_space_marine;
		m_space_marine = 0;
	}

	if (m_nomad)
	{
		m_nomad->Shutdown();
		delete m_nomad;
		m_nomad = 0;
	}

	if (m_worker)
	{
		m_worker->Shutdown();
		delete m_worker;
		m_worker = 0;
	}

	if (m_Droid)
	{
		m_Droid->Shutdown();
		delete m_Droid;
		m_Droid = 0;
	}

	if (m_bloodwing)
	{
		m_bloodwing->Shutdown();
		delete m_bloodwing;
		m_bloodwing = 0;
	}

	if (m_UFO)
	{
		m_UFO->Shutdown();
		delete m_UFO;
		m_UFO = 0;
	}

	if (m_Sofa1)
	{
		m_Sofa1->Shutdown();
		delete m_Sofa1;
		m_Sofa1 = 0;
	}

	if (m_Sofa2)
	{
		m_Sofa2->Shutdown();
		delete m_Sofa2;
		m_Sofa2 = 0;
	}

	if (m_Bench2)
	{
		m_Bench2->Shutdown();
		delete m_Bench2;
		m_Bench2 = 0;
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

	if (m_chair05)
	{
		m_chair05->Shutdown();
		delete m_chair05;
		m_chair05 = 0;
	}

	if (m_chair01)
	{
		m_chair01->Shutdown();
		delete m_chair01;
		m_chair01 = 0;
	}

	if (m_Table_Chair01)
	{
		m_Table_Chair01->Shutdown();
		delete m_Table_Chair01;
		m_Table_Chair01 = 0;
	}

	if (m_Table_Chair02)
	{
		m_Table_Chair02->Shutdown();
		delete m_Table_Chair02;
		m_Table_Chair02 = 0;
	}

	if (m_Furniture2)
	{
		m_Furniture2->Shutdown();
		delete m_Furniture2;
		m_Furniture2 = 0;
	}

	if (m_wooden_sofa1)
	{
		m_wooden_sofa1->Shutdown();
		delete m_wooden_sofa1;
		m_wooden_sofa1 = 0;
	}
	if (m_wooden_sofa2)
	{
		m_wooden_sofa2->Shutdown();
		delete m_wooden_sofa2;
		m_wooden_sofa2 = 0;
	}

	if (m_wooden_sofa3)
	{
		m_wooden_sofa3->Shutdown();
		delete m_wooden_sofa3;
		m_wooden_sofa3 = 0;
	}

	if (m_wooden_sofa4)
	{
		m_wooden_sofa4->Shutdown();
		delete m_wooden_sofa4;
		m_wooden_sofa4 = 0;
	}

	if (m_wooden_sofa5)
	{
		m_wooden_sofa5->Shutdown();
		delete m_wooden_sofa5;
		m_wooden_sofa5 = 0;
	}

	if (m_wooden_sofa6)
	{
		m_wooden_sofa6->Shutdown();
		delete m_wooden_sofa6;
		m_wooden_sofa6 = 0;
	}

	if (m_wooden_sofa7)
	{
		m_wooden_sofa7->Shutdown();
		delete m_wooden_sofa7;
		m_wooden_sofa7 = 0;
	}

	if (m_wooden_sofa8)
	{
		m_wooden_sofa8->Shutdown();
		delete m_wooden_sofa8;
		m_wooden_sofa8 = 0;
	}

	if (m_woodStand)
	{
		m_woodStand->Shutdown();
		delete m_woodStand;
		m_woodStand = 0;
	}

	if (m_car)
	{
		m_car->Shutdown();
		delete m_car;
		m_car = 0;
	}

	if (m_car2)
	{
		m_car2->Shutdown();
		delete m_car2;
		m_car2 = 0;
	}

	if (m_sign01)
	{
		m_sign01->Shutdown();
		delete m_sign01;
		m_sign01 = 0;
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

		m_board1->Shutdown();
		delete m_board1;
		m_board1 = 0;

		m_board2->Shutdown();
		delete m_board2;
		m_board2 = 0;

		#pragma endregion
	}



#pragma endregion
		
	#pragma endregion
}

/*
	Frame 함수가 unity의 update함수와 같은 역할이라고 보면 됨.
	대부분의 반복되는 작업들이 대부분 이 안에 들어있음.
	인수가 조금 많지만, 카메라를 움직이게 하려면 어쩔수 없음
*/
bool GraphicsClass::Frame(int fps, int cpu, float frameTime, int mouseX, int mouseY, float left, float right, float front, float behind, float up, float down, float bit, bool moved,
						  float ob_left, float ob_right, float ob_up, float ob_down, float ob_front, float ob_behind)
{
	bool result;
    
	
	#pragma region UI information
	
	// Set the location of the mouse.
	result = m_Text->SetMousePosition(mouseX, mouseY, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the location of the mouse.
	result = m_Text->SetKeyBoardPosition(left, right, front, behind, up, down, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the frames per second.
	result = m_Text->SetFps(fps/2, m_D3D->GetDeviceContext());
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

	// Update the position of the water to simulate motion.
	m_waterTranslation += 0.001f;
	if (m_waterTranslation > 1.0f)
	{
		m_waterTranslation -= 1.0f;
	}

	/*
		moved가 TRUE이면 원래 카메라,
		moved가 FALSE가 되면, 차 속으로 이동한다.

		TRUE일 때는 차도 가만히 있고, m_Camera__도 가만히 있어야 한다.

		그리고 FALSE가 되면 m_Camera가 차속으로 이동하면서 차도 움직이고, m_Camera 도 움직일 수 있도록 해야한다.
	*/

	if (moved == TRUE) {
		m_Camera->SetPosition(250.0f + left + right, 20.0f + up + down, -280.0f + front + behind);
		// 마우스가 화면에 닿으면 안 움직이는 것은 정상임. 이건 따로 고칠 필요 없음.
		m_Camera->SetRotation((mouseY - 600) * 0.5f, (mouseX - 960) * 0.5f, 0.0f);
	}

	// 그리고 moved가 FALSE가 되면, 2번 카메라가 작동한다. 이 카메라는 차 속에 있도록 해야한다. 
	else {
		// 현재 차의 위치이다.
		m_Camera__->SetPosition(190.0f + ob_left + ob_right, 37.0f, 76.0f + ob_front + ob_behind);
		m_Camera__->SetRotation((mouseY - 600) * 0.5f, (mouseX - 960) * 0.5f, 0.0f);
	}

	m_Camera_->SetPosition(bit, 0.0f, -10.0f);

	return true;
}

//
//bool GraphicsClass::RenderToTexture()
//{
//	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix, translate, scale;
//	bool result;
//
//
//	// Set the render target to be the render to texture.
//	m_RenderTexture->SetRenderTarget(m_D3D->GetDeviceContext(), m_D3D->GetDepthStencilView());
//
//	// Clear the render to texture.
//	m_RenderTexture->ClearRenderTarget(m_D3D->GetDeviceContext(), m_D3D->GetDepthStencilView(), 0.0f, 0.0f, 0.0f, 1.0f);
//
//	// Generate the view matrix based on the camera's position.
//	m_Camera->Render();
//
//	// Get the world, view, and projection matrices from the camera and d3d objects.
//	m_D3D->GetWorldMatrix(worldMatrix);
//	m_Camera->GetViewMatrix(viewMatrix);
//	m_D3D->GetProjectionMatrix(projectionMatrix);
//
//	D3DXMATRIX worldMatrix_House;
//	D3DXMatrixTranslation(&translate, 0.0f, 0.0f, 0.0f);
//	D3DXMatrixScaling(&scale, 0.1f, 0.1f, 0.1f);
//	worldMatrix_House = worldMatrix * translate * scale;
//	// Put the cube model vertex and index buffers on the graphics pipeline to prepare them for drawing.
//	m_House1->Render(m_D3D->GetDeviceContext());
//
//	// Render the cube model using the texture shader.
//	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_House1->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix, m_House1->GetTexture());
//	if (!result)
//	{
//		return false;
//	}
//
//	// Put the cube model vertex and index buffers on the graphics pipeline to prepare them for drawing.
//	m_House3->Render(m_D3D->GetDeviceContext());
//
//	// Render the cube model using the texture shader.
//	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_House3->GetIndexCount(), worldMatrix_House, viewMatrix, projectionMatrix, m_House3->GetTexture());
//	if (!result)
//	{
//		return false;
//	}
//
//	// Reset the render target back to the original back buffer and not the render to texture anymore.
//	m_D3D->SetBackBufferRenderTarget();
//
//	return true;
//}


bool GraphicsClass::Render(float ob_left, float ob_right, float ob_up, float ob_down, float ob_front, float ob_behind, bool moved)
{
	D3DXMATRIX worldMatrix, viewMatrix, viewMatrix_, projectionMatrix, orthoMatrix, translate, scale;
	bool result;

	#pragma region rotation
	
	static float rotation = 0.0f;
	static float rotation_ = 0.0f;

	// Update the rotation variable each frame.
	rotation += (float)D3DX_PI * 0.003f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	rotation_ -= (float)D3DX_PI * 0.002f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	#pragma endregion

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
	if (moved == TRUE) {
		// Generate the view matrix based on the camera's position.
		m_Camera->Render();
		// Get the view, projection, and world matrices from the camera and D3D objects.
		m_Camera->GetViewMatrix(viewMatrix);
	}
	else {
		// Generate the view matrix based on the camera's position.
		m_Camera__->Render();
		// Get the view, projection, and world matrices from the camera and D3D objects.
		m_Camera__->GetViewMatrix(viewMatrix);
	}

	// for a bitmap
	m_Camera_->Render();

	// for a bitmap
	m_Camera_->GetViewMatrix(viewMatrix_);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);
	m_D3D->GetOrthoMatrix(orthoMatrix);

	#pragma region 2DRendering

	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 0, -30);
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

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap2->Render(m_D3D->GetDeviceContext(), -2000, 140);
	if (!result)
	{
		return false;
	}

	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap2->GetIndexCount(), worldMatrix, viewMatrix_, orthoMatrix, m_Bitmap2->GetTexture());
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

	D3DXMATRIX worldMatrix_CarObj;
	D3DXMatrixTranslation(&translate, 200.0f + ob_left + ob_right, 4.0f, 80.0f + ob_front + ob_behind);
	D3DXMatrixRotationY(&worldMatrix, (ob_up + ob_down) * 0.2f);
	worldMatrix_CarObj = worldMatrix * translate;
	m_Carobj->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Carobj->GetIndexCount(), worldMatrix_CarObj, viewMatrix, projectionMatrix,
		m_Carobj->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_D3D->GetWorldMatrix(worldMatrix);

	D3DXMATRIX worldMatrix_Lego;
	D3DXMatrixTranslation(&translate, 300.0f, -20.0f, 160.0f);
	D3DXMatrixScaling(&scale, 0.25f, 0.25f, 0.25f);
	worldMatrix_Lego = worldMatrix * translate;
	D3DXMatrixRotationY(&worldMatrix_Lego, 80.0f);

	m_lego1->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_lego1->GetIndexCount(), worldMatrix_Lego, viewMatrix, projectionMatrix,
		m_lego1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_lego2->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_lego2->GetIndexCount(), worldMatrix_Lego, viewMatrix, projectionMatrix,
		m_lego2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_D3D->GetWorldMatrix(worldMatrix);

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
		m_House2->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
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
		m_House4->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
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

	
	#pragma region sofa1
	
	//D3DXMATRIX worldMatrix_sofa1;
	//D3DXMatrixTranslation(&translate, -3.3f, 2.5f, -3.2f);
	//D3DXMatrixScaling(&scale, 10.0f, 10.0f, 10.0f);
	//worldMatrix_sofa1 = worldMatrix * translate * scale;

	//m_Sofa1->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Sofa1->GetIndexCount(), worldMatrix_sofa1, viewMatrix, projectionMatrix,
	//	m_Sofa1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_sofa2;
	//D3DXMatrixTranslation(&translate, -5.0f, 2.5f, 5.2f);
	//D3DXMatrixScaling(&scale, 10.0f, 10.0f, 10.0f);
	//worldMatrix_sofa2 = worldMatrix * translate * scale;

	//m_Sofa2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Sofa2->GetIndexCount(), worldMatrix_sofa2, viewMatrix, projectionMatrix,
	//	m_Sofa2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region Bench2

	//D3DXMATRIX worldMatrix_Bench2;
	//D3DXMatrixTranslation(&translate, -10.0f, 4.1f, -22.0f);
	//D3DXMatrixScaling(&scale, 5.0f, 5.0f, 5.0f);
	//worldMatrix_Bench2 = worldMatrix * translate * scale;

	//m_Bench2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Bench2->GetIndexCount(), worldMatrix_Bench2, viewMatrix, projectionMatrix,
	//	m_Bench2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMatrixTranslation(&translate, 0.0f, 4.1f, -22.0f);
	//D3DXMatrixScaling(&scale, 5.0f, 5.0f, 5.0f);
	//worldMatrix_Bench2 = worldMatrix * translate * scale;

	//m_Bench2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Bench2->GetIndexCount(), worldMatrix_Bench2, viewMatrix, projectionMatrix,
	//	m_Bench2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMatrixTranslation(&translate, 10.0f, 4.1f, -22.0f);
	//D3DXMatrixScaling(&scale, 5.0f, 5.0f, 5.0f);
	//worldMatrix_Bench2 = worldMatrix * translate * scale;

	//m_Bench2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Bench2->GetIndexCount(), worldMatrix_Bench2, viewMatrix, projectionMatrix,
	//	m_Bench2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region Desk

	//D3DXMATRIX worldMatrix_Desk;
	//D3DXMatrixTranslation(&translate, 4.1f, 3.3f, -7.0f);
	//D3DXMatrixScaling(&scale, 7.0f, 7.0f, 7.0f);
	//worldMatrix_Desk = worldMatrix * translate * scale;

	//m_Desk->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Desk->GetIndexCount(), worldMatrix_Desk, viewMatrix, projectionMatrix,
	//	m_Desk->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());

	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_Wood_desk;
	//D3DXMatrixTranslation(&translate, -7.0f, 3.2f, -1.7f);
	//D3DXMatrixScaling(&scale, 7.0f, 7.0f, 7.0f);
	//worldMatrix_Wood_desk = worldMatrix * translate * scale;

	//m_Wood_desk->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Wood_desk->GetIndexCount(), worldMatrix_Wood_desk, viewMatrix, projectionMatrix,
	//	m_Wood_desk->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region chair
	//
	//D3DXMATRIX worldMatrix_chair05;
	//D3DXMatrixTranslation(&translate, -20.0f, 43.0f, 65.0f);
	//D3DXMatrixScaling(&scale, 0.5f, 0.5f, 0.5f);
	//worldMatrix_chair05 = worldMatrix * translate * scale;

	//m_chair05->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_chair05->GetIndexCount(), worldMatrix_chair05, viewMatrix, projectionMatrix,
	//	m_chair05->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_chair01;
	//D3DXMatrixTranslation(&translate, 35.0f, 23.0f, 13.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_chair01 = worldMatrix * translate * scale;

	//m_chair01->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_chair01->GetIndexCount(), worldMatrix_chair01, viewMatrix, projectionMatrix,
	//	m_chair01->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_Table_chair01;
	//D3DXMatrixTranslation(&translate, 51.0f, 23.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_Table_chair01 = worldMatrix * translate * scale;

	//m_Table_Chair01->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Table_Chair01->GetIndexCount(), worldMatrix_Table_chair01, viewMatrix, projectionMatrix,
	//	m_Table_Chair01->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_Table_chair02;
	//D3DXMatrixTranslation(&translate, 51.0f, 23.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_Table_chair02 = worldMatrix * translate * scale;

	//m_Table_Chair02->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Table_Chair02->GetIndexCount(), worldMatrix_Table_chair02, viewMatrix, projectionMatrix,
	//	m_Table_Chair02->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion
	//
	//#pragma region Furniture2

	//D3DXMATRIX worldMatrix_Furniture2;
	//D3DXMatrixTranslation(&translate, 380.0f, 400.0f, 550.0f);
	//D3DXMatrixScaling(&scale, 0.1f, 0.1f, 0.1f);
	//worldMatrix_Furniture2 = worldMatrix * translate * scale;

	//m_Furniture2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Furniture2->GetIndexCount(), worldMatrix_Furniture2, viewMatrix, projectionMatrix,
	//	m_Furniture2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region wooden_sofa

	//D3DXMATRIX worldMatrix_wooden_sofa1;
	//D3DXMatrixTranslation(&translate, -40.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa1 = worldMatrix * translate * scale;

	//m_wooden_sofa1->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa1->GetIndexCount(), worldMatrix_wooden_sofa1, viewMatrix, projectionMatrix,
	//	m_wooden_sofa1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa2;
	//D3DXMatrixTranslation(&translate, -40.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa2 = worldMatrix * translate * scale;

	//m_wooden_sofa2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa2->GetIndexCount(), worldMatrix_wooden_sofa2, viewMatrix, projectionMatrix,
	//	m_wooden_sofa2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa3;
	//D3DXMatrixTranslation(&translate, -15.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa3 = worldMatrix * translate * scale;

	//m_wooden_sofa3->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa3->GetIndexCount(), worldMatrix_wooden_sofa3, viewMatrix, projectionMatrix,
	//	m_wooden_sofa3->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa4;
	//D3DXMatrixTranslation(&translate, -15.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa4 = worldMatrix * translate * scale;

	//m_wooden_sofa4->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa4->GetIndexCount(), worldMatrix_wooden_sofa4, viewMatrix, projectionMatrix,
	//	m_wooden_sofa4->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa5;
	//D3DXMatrixTranslation(&translate, 10.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa5 = worldMatrix * translate * scale;

	//m_wooden_sofa5->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa5->GetIndexCount(), worldMatrix_wooden_sofa5, viewMatrix, projectionMatrix,
	//	m_wooden_sofa5->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa6;
	//D3DXMatrixTranslation(&translate, 10.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa6 = worldMatrix * translate * scale;

	//m_wooden_sofa6->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa6->GetIndexCount(), worldMatrix_wooden_sofa6, viewMatrix, projectionMatrix,
	//	m_wooden_sofa6->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa7;
	//D3DXMatrixTranslation(&translate, 35.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa7 = worldMatrix * translate * scale;

	//m_wooden_sofa7->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa7->GetIndexCount(), worldMatrix_wooden_sofa7, viewMatrix, projectionMatrix,
	//	m_wooden_sofa7->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMATRIX worldMatrix_wooden_sofa8;
	//D3DXMatrixTranslation(&translate, 35.0f, 23.0f, 100.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_wooden_sofa8 = worldMatrix * translate * scale;

	//m_wooden_sofa8->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_wooden_sofa8->GetIndexCount(), worldMatrix_wooden_sofa8, viewMatrix, projectionMatrix,
	//	m_wooden_sofa8->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region woodstand

	//D3DXMATRIX worldMatrix_woodstand;
	//D3DXMatrixTranslation(&translate, 6.0f, 2.5f, 1.5f);
	//D3DXMatrixScaling(&scale, 10.0f, 10.0f, 10.0f);
	//worldMatrix_woodstand = worldMatrix * translate * scale;

	//m_woodStand->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_woodStand->GetIndexCount(), worldMatrix_woodstand, viewMatrix, projectionMatrix,
	//	m_woodStand->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}
	//
	//#pragma endregion

	//#pragma region car

	//D3DXMATRIX worldMatrix_car;
	//
	//D3DXMatrixTranslation(&translate, -30.0f, 55.0f, 60.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//worldMatrix_car = worldMatrix * translate * scale;

	//m_car->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_car->GetIndexCount(), worldMatrix_car, viewMatrix, projectionMatrix,
	//	m_car->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}
	//
	//D3DXMATRIX worldMatrix_car2;
	//D3DXMatrixTranslation(&translate, 2.0f, 6.0f, 6.0f);
	//D3DXMatrixScaling(&scale, 10.0f, 10.0f, 10.0f);
	//worldMatrix_car2 = worldMatrix * translate * scale;

	//m_car2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_car2->GetIndexCount(), worldMatrix_car2, viewMatrix, projectionMatrix,
	//	m_car2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}
	//
	//#pragma endregion

	//#pragma region sign

	//D3DXMATRIX worldMatrix_sign;
	//D3DXMatrixTranslation(&translate, -60.0f, 53.0f, -40.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixRotationY(&worldMatrix, 180.0f);
	//worldMatrix_sign = worldMatrix * translate * scale;

	//m_sign01->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_sign01->GetIndexCount(), worldMatrix_sign, viewMatrix, projectionMatrix,
	//	m_sign01->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//D3DXMatrixTranslation(&translate, 60.0f, 53.0f, -40.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixRotationY(&worldMatrix, 360.0f);
	//worldMatrix_sign = worldMatrix * translate * scale;

	//m_sign01->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_sign01->GetIndexCount(), worldMatrix_sign, viewMatrix, projectionMatrix,
	//	m_sign01->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region Board

	//D3DXMATRIX worldMatrix_Board;
	//D3DXMatrixTranslation(&translate, -200.0f, 0.0f, -180.0f);
	//D3DXMatrixScaling(&scale, 0.525f, 0.525f, 0.525f);
	//D3DXMatrixRotationY(&worldMatrix, 230.0f);

	//worldMatrix_Board = worldMatrix * translate * scale;
	//m_board1->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_board1->GetIndexCount(), worldMatrix_Board, viewMatrix, projectionMatrix,
	//	m_board1->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());

	//worldMatrix_Board = worldMatrix * translate * scale;
	//m_board2->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_board2->GetIndexCount(), worldMatrix_Board, viewMatrix, projectionMatrix,
	//	m_board2->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());

	//#pragma endregion

	//#pragma region Character

	//#pragma region storm_trooper
	//
	//D3DXMATRIX worldMatrix_storm_trooper;
	//D3DXMatrixTranslation(&translate, 0.0f, 28.3f, -55.0f);
	//D3DXMatrixScaling(&scale, 0.8f, 0.8f, 0.8f);
	//D3DXMatrixRotationY(&worldMatrix, 90.0f);
	//worldMatrix_storm_trooper = worldMatrix * translate * scale;

	//m_storm_trooper->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_storm_trooper->GetIndexCount(), worldMatrix_storm_trooper, viewMatrix, projectionMatrix,
	//	m_storm_trooper->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}
	//
	//#pragma endregion

	//#pragma region space_marine
	//
	//D3DXMATRIX worldMatrix_space_marine;
	//D3DXMatrixTranslation(&translate, 33.0f, 32.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 0.7f, 0.7f, 0.7f);
	//D3DXMatrixRotationY(&worldMatrix, -70.0f);
	//worldMatrix_space_marine = worldMatrix * translate * scale;

	//m_space_marine->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_space_marine->GetIndexCount(), worldMatrix_space_marine, viewMatrix, projectionMatrix,
	//	m_space_marine->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}
	//
	//#pragma endregion

	//#pragma region nomad
	//
	//D3DXMATRIX worldMatrix_nomad;
	//D3DXMatrixTranslation(&translate, 30.0f, 23.0f, 83.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixRotationY(&worldMatrix, 60.0f);
	//worldMatrix_nomad = worldMatrix * translate * scale;

	//m_nomad->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_nomad->GetIndexCount(), worldMatrix_nomad, viewMatrix, projectionMatrix,
	//	m_nomad->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}
	//
	//#pragma endregion


	//#pragma region worker
	//
	//D3DXMATRIX worldMatrix_worker;
	//D3DXMatrixTranslation(&translate, 30.0f, 55.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixRotationY(&worldMatrix, 0.0f);
	//worldMatrix_worker = worldMatrix * translate * scale;

	//m_worker->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_worker->GetIndexCount(), worldMatrix_worker, viewMatrix, projectionMatrix,
	//	m_worker->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region Droid
	//
	//D3DXMATRIX worldMatrix_Droid;
	//D3DXMatrixTranslation(&translate, 0.0f, 55.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixRotationY(&worldMatrix, -80.0f);
	//worldMatrix_Droid = worldMatrix * translate * scale;

	//m_Droid->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Droid->GetIndexCount(), worldMatrix_Droid, viewMatrix, projectionMatrix,
	//	m_Droid->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//#pragma endregion

	//#pragma region Bloodwing
	//
	//D3DXMATRIX worldMatrix_Bloodwing;
	//D3DXMatrixTranslation(&translate, -2.0f, 101.0f, 0.0f);
	//D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixRotationY(&worldMatrix, 0.0f);
	//worldMatrix_Bloodwing = worldMatrix * translate * scale;

	//m_bloodwing->Render(m_D3D->GetDeviceContext());
	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_bloodwing->GetIndexCount(), worldMatrix_Bloodwing, viewMatrix, projectionMatrix,
	//	m_bloodwing->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	#pragma endregion

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

	#pragma region UFO
	
	m_D3D->GetWorldMatrix(worldMatrix);

	D3DXMATRIX worldMatrix_UFO;

	D3DXMatrixTranslation(&translate, 200.0f, 220.0f, 0.0f);
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	D3DXMatrixRotationY(&worldMatrix, rotation);

	worldMatrix_UFO = translate * scale* worldMatrix;
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_UFO->Render(m_D3D->GetDeviceContext());
	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_UFO->GetIndexCount(), worldMatrix_UFO, viewMatrix, projectionMatrix,
		m_UFO->GetTexture(), m_Light_->GetDirection(), m_Light_->GetAmbientColor(), m_Light_->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_->GetSpecularColor(), m_Light_->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	
	#pragma endregion
//
	#pragma endregion
	#pragma endregion

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}

