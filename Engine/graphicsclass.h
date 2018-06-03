////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "textclass.h"

#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"
#include "textureshaderclass.h"
#include "bitmapclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


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
	bool Frame(int, int, float, int, int, float, float, float, float, float, float);
	
	bool Render();
private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;

	// For Bitmap
	CameraClass* m_Camera_;
	
	TextureShaderClass* m_TextureShader;
	
	ModelClass* m_Dva1;	ModelClass* m_Dva2;
	ModelClass* m_Hanzo;
	
	ModelClass* m_Boardsign;
	ModelClass* m_Tile;					
	ModelClass* m_Sofa1;
	ModelClass* m_chair05;
	ModelClass* m_Bench2;
	ModelClass* m_Furniture2;
	ModelClass*m_Staircase;
	ModelClass* m_Lamp;
	ModelClass* m_Desk;
	ModelClass* m_Wood_desk;
	ModelClass* m_woodStand;
	ModelClass* m_computer_table;


	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	LightClass* m_Light_;
	BitmapClass* m_Bitmap;
	TextClass* m_Text;
};

#endif