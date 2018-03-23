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
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Toroide.h"
#include "Cilindro.h"
#include "Rombo.h"
#include "Cono.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
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
	bool Frame();

private:
	bool Render(float);
	
private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	ModelClass *m_Sun;
	ModelClass *m_Sun2;
	ModelClass** m_Cadena;
	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	TextureClass* m_TextDirt;
	TextureClass* m_Blend;
	
};

#endif