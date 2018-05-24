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
	ModelClass* m_House1;	ModelClass* m_House2;	ModelClass* m_House3;	ModelClass* m_House4;	ModelClass* m_House5;
	

	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	LightClass* m_Light_;
	BitmapClass* m_Bitmap;
	TextClass* m_Text;
};

#endif