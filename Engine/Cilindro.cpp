#include "Cilindro.h"



Cilindro::Cilindro()
{
	height = 2;
	topRadius = 1;
	bottomRadius = 1;
	segments = 8;
}

Cilindro::Cilindro(double height, double topRadius, double bottomRadius, int segments)
{
	this->height = height;
	this->topRadius = topRadius;
	this->bottomRadius = bottomRadius;
	this->segments = segments;
}

Cilindro::~Cilindro()
{
}

void Cilindro::drawCylinder(double height, double topRadius, double bottomRadius, int segments)
{
	float topHeight = height / 2;
	float bottomHeight = -(height / 2);
	int index = 0;

	m_vertexCount = (segments + 2) * 2;
	m_indexCount = (segments * 6) + 2 * (segments * 3);

	vertices = new VertexType[m_vertexCount];
	indices = new unsigned long[m_indexCount];

	drawTopCap(topHeight, topRadius, segments, &index);
	drawBottomCap(bottomHeight, bottomRadius, segments, &index);

	int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
	int offset = segments + 2;
	for (int i = 0; i < segments; i++)
	{
		index1 = i;
		index2 = i + 1;
		index3 = offset + i;
		index4 = offset + i + 1;

		indices[index++] = index1;
		indices[index++] = index2;
		indices[index++] = index4;

		indices[index++] = index4;
		indices[index++] = index3;
		indices[index++] = index1;
	}


}

void Cilindro::drawTopCap(double height, double radio, int segments, int*  index)
{
	if (!index)
		return;

	float angle = (2 * D3DX_PI) / segments;

	for (int i = 0; i <= segments; i++)
	{
		//Vertices
		vertices[i].position.x = radio * cos(i * angle);
		vertices[i].position.y = height;
		vertices[i].position.z = radio * sin(i * angle);

		//Normales
		vertices[i].normal.x = cos(i *angle);
		vertices[i].normal.y = height;
		vertices[i].normal.z = sin(i * angle);

		//Textura
		vertices[i].texture.x = (1 - (double)i / (segments));
		vertices[i].texture.y = (1 - (double)i / (segments));
	}

	vertices[segments + 1].position.x = 0;
	vertices[segments + 1].position.y = height;
	vertices[segments + 1].position.z = 0;

	//Normales
	vertices[segments + 1].normal.x = cos(angle);
	vertices[segments + 1].normal.y = height;
	vertices[segments + 1].normal.z = sin(angle);

	//Textura
	vertices[segments + 1].texture.x = 1 - 0.5;
	vertices[segments + 1].texture.y = 1 - 0.5;

	int centro = segments + 1;

	for (int i = 0; i < segments; i++)
	{
		indices[(*index)++] = centro;
		indices[(*index)++] = i + 1;
		indices[(*index)++] = i;
	}
}

void Cilindro::drawBottomCap(double height, double radio, int segments, int*  index)
{
	if (!index)
		return;

	float angle = (2 * D3DX_PI) / segments;
	int offset = segments + 2;

	for (int i = 0; i <= segments; i++)
	{
		//Vertices
		vertices[offset + i].position.x = radio * cos(i * angle);
		vertices[offset + i].position.y = height;
		vertices[offset + i].position.z = radio * sin(i * angle);

		//Normales
		vertices[offset + i].normal.x = cos(i *angle);
		vertices[offset + i].normal.y = height;
		vertices[offset + i].normal.z = sin(i * angle);

		//Textura
		vertices[offset + i].texture.x = (1 - (double)i / (segments));
		vertices[offset + i].texture.y = (1 - (double)i / (segments));
	}

	vertices[offset + segments + 1].position.x = 0;
	vertices[offset + segments + 1].position.y = height;
	vertices[offset + segments + 1].position.z = 0;

	//Normales
	vertices[offset + segments + 1].normal.x = cos(angle);
	vertices[offset + segments + 1].normal.y = height;
	vertices[offset + segments + 1].normal.z = sin(angle);

	//Textura
	vertices[offset + segments + 1].texture.x = 1 - 0.5;
	vertices[offset + segments + 1].texture.y = 1 - 0.5;

	int centro = offset + segments + 1;

	for (int i = 0; i < segments; i++)
	{
		indices[(*index)++] = offset + i;
		indices[(*index)++] = offset + i + 1;
		indices[(*index)++] = centro;
	}
}

bool Cilindro::Estrategia()
{
	drawCylinder(height, topRadius, bottomRadius, segments);
	return true;
}