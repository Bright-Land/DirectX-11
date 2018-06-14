////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "textclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "glassshaderclass.h"
#include "bumpmapshaderclass.h"
#include "lightclass.h"
#include "textureshaderclass.h"
#include "bitmapclass.h"
#include "rendertextureclass.h"
#include "refractionshaderclass.h"
#include "watershaderclass.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(int, int, float, int, int, float, float, float, float, float, float, float, bool, float, float, float, float, float, float);
	bool Render(float, float, float, float, float, float, bool);


private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	// For Bitmap
	CameraClass* m_Camera_;
	CameraClass* m_Camera__;
	TextureShaderClass* m_TextureShader;
	GlassShaderClass* m_GlassShader;
	RenderTextureClass* m_RenderTexture;

	#pragma region m_Model

	ModelClass* m_Dva1, *m_Dva2;
	ModelClass* m_storm_trooper;
	ModelClass* m_space_marine;
	ModelClass* m_nomad;
	ModelClass* m_worker;
	ModelClass* m_Droid;
	ModelClass* m_bloodwing;
	ModelClass* m_lego1, *m_lego2;
	ModelClass* m_Carobj;

	ModelClass* m_House1, *m_House2, *m_House3, *m_House4, *m_House5;
	ModelClass* m_tile1, *m_tile2;

	ModelClass* m_board1, *m_board2;

	//비행 오브젝트
	ModelClass* m_UFO;

	//가구 오브젝트
	ModelClass* m_Sofa1;
	ModelClass* m_Sofa2;

	ModelClass* m_Bench2;

	ModelClass* m_Desk;

	ModelClass* m_Wood_desk;

	ModelClass* m_chair05;
	ModelClass* m_chair01;

	ModelClass* m_Table_Chair01;
	ModelClass* m_Table_Chair02;

	ModelClass* m_wooden_sofa1;
	ModelClass* m_wooden_sofa2;

	ModelClass* m_wooden_sofa3;
	ModelClass* m_wooden_sofa4;

	ModelClass* m_wooden_sofa5;
	ModelClass* m_wooden_sofa6;

	ModelClass* m_wooden_sofa7;
	ModelClass* m_wooden_sofa8;

	ModelClass* m_Furniture2;

	ModelClass* m_woodStand;


	//자동차
	ModelClass* m_car;
	ModelClass* m_car2;

	ModelClass* m_sign01;

	#pragma endregion
	
	LightShaderClass* m_LightShader;
	BumpMapShaderClass* m_BumpMapShader;
	LightClass* m_Light;
	LightClass* m_Light_;
	LightClass* m_Light__;
	BitmapClass* m_Bitmap;
	BitmapClass* m_Bitmap2;
	TextClass* m_Text;

	RenderTextureClass *m_RefractionTexture, *m_ReflectionTexture;
	RefractionShaderClass* m_RefractionShader;
	WaterShaderClass* m_WaterShader;
	float m_waterHeight, m_waterTranslation;
};

#endif