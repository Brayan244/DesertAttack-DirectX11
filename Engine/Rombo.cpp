#include "Rombo.h"



Rombo::Rombo()
{
	height = 2;
	radio = 1;
	segmentos = 8;
}

Rombo::Rombo(double heigth, double radio, int segmentos)
{
	this->height = heigth;
	this->radio = radio;
	this->segmentos = segmentos;
}


Rombo::~Rombo()
{
}

void Rombo::drawRomboid(double height, double radio, int segmentos)
{
	float angle = 2.0f * D3DX_PI / segmentos;
	float topHeight = height / 2;
	float bottomHeigth = -(height / 2);

	m_vertexCount = segmentos + 4;
	m_indexCount = segmentos * 6;

	//Creamos un arreglo de vertices
	vertices = new VertexType[m_vertexCount];
	indices = new unsigned long[m_indexCount];

	for (int i = 0; i <= segmentos; i++)
	{
		//Vertices
		vertices[i].position.x = radio * cos(i *angle);
		vertices[i].position.y = 0;
		vertices[i].position.z = radio * sin(i * angle);

		//Normales
		vertices[i].normal.x = cos(i *angle);
		vertices[i].normal.y = 0;
		vertices[i].normal.z = sin(i * angle);

		//Textura
		vertices[i].texture.x = (1 - (double)i / (segmentos));
		vertices[i].texture.y = (1 - (double)i / (segmentos));
	}

	vertices[m_vertexCount - 2].position.x = 0;
	vertices[m_vertexCount - 2].position.y = bottomHeigth;
	vertices[m_vertexCount - 2].position.z = 0;

	//Normales
	vertices[m_vertexCount - 2].normal.x = cos(angle);
	vertices[m_vertexCount - 2].normal.y = 0;
	vertices[m_vertexCount - 2].normal.z = sin(angle);

	//Textura
	vertices[m_vertexCount - 2].texture.x = 1 - 0.5;
	vertices[m_vertexCount - 2].texture.y = 1 - 0.5;


	vertices[m_vertexCount - 1].position.x = 0;
	vertices[m_vertexCount - 1].position.y = topHeight;
	vertices[m_vertexCount - 1].position.z = 0;

	//Normales
	vertices[m_vertexCount - 1].normal.x = angle;
	vertices[m_vertexCount - 1].normal.y = 0;
	vertices[m_vertexCount - 1].normal.z = angle;

	//Textura
	vertices[m_vertexCount - 1].texture.x = 1 - 0.5;
	vertices[m_vertexCount - 1].texture.y = 1 - 0.5;

	int centro = m_vertexCount - 2, index = 0, altura = m_vertexCount - 1;

	for (int i = 0; i < segmentos; i++)
	{
		indices[index++] = i;
		indices[index++] = i + 1;
		indices[index++] = centro;

		indices[index++] = altura;
		indices[index++] = i + 1;
		indices[index++] = i;
	}


}

bool Rombo::Estrategia()
{
	drawRomboid(height, radio, segmentos);
	return true;
}