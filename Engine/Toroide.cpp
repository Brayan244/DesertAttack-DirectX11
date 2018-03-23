#include "Toroide.h"



Toroide::Toroide()
{
}

Toroide::~Toroide()
{
}

bool Toroide::Estrategia()
{

	drawTorus(0.40, 0.10, 32, 32);
	
	return true;
}

void Toroide::drawTorus(double r = 0.07, double c = 0.15, int rSeg = 16, int cSeg = 8)
{
	float Ro = 0.0f;
	float Theta = 0.0f;

	//Obtenemos el total de vertices e indices
	m_vertexCount = (rSeg + 1) * (cSeg + 1);
	m_indexCount = (rSeg ) * (cSeg ) * 6;

	//Creamos un arreglo de vertices
	vertices = new VertexType[m_vertexCount];
	indices = new unsigned long[m_indexCount];

	Ro = (float)(2 * D3DX_PI) / rSeg;
	Theta = (float)(2 * D3DX_PI) / cSeg;

	for (int i = 0; i <=  rSeg; i++)
	{
		for (int j = 0; j <=  cSeg; j++)
		{
			int indice = (i * rSeg) + j;

			//Vertices
			vertices[indice].position.x = cos(Ro * i) * (r + (float)(c * cos(Theta * j)));
			vertices[indice].position.y = sin(Ro * i) * (r + (float)(c * cos(Theta * j)));
			vertices[indice].position.z = (float)c * sin(Theta * j);

			//Normales
			vertices[indice].normal.x = cos(Ro * i) * cos(Theta * j);
			vertices[indice].normal.y = sin(Ro * i) * cos(Theta * j);
			vertices[indice].normal.z = sin(Theta * j);

			//Textura
			vertices[indice].texture.x = (1 - (double)i / (cSeg));
			vertices[indice].texture.y = (1 - (double)j / (rSeg));
		}
	}

	int index = 0, index1 = 0, index2 = 0, index3 = 0, index4 = 0;

	for (int i = 0; i < rSeg ; i++)
	{
		for (int j = 0; j < cSeg  ; j++)
		{
			index1 = (rSeg *   i) + j;    // Bottom left.
			index2 = (rSeg *   i) + (j + 1);  // Bottom right.
			index3 = (rSeg * (i + 1)) + j;    // Upper left.
			index4 = (rSeg * (i + 1)) + (j + 1);  // Upper right.

			indices[index++] = index4;
			indices[index++] = index2;
			indices[index++] = index1;

			indices[index++] = index3;
			indices[index++] = index4;
			indices[index++] = index1;
		}
	}	
}

