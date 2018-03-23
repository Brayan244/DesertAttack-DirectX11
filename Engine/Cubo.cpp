#include "Cubo.h"



Cubo::Cubo()
{
}


Cubo::~Cubo()
{
}

bool Cubo::Estrategia()
{
	int i = 0;
	m_vertexCount = 8;
	m_indexCount = 36;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	// Load the vertex array and index array with data.
	/*for(i=0; i<m_vertexCount; i++)
	{
	vertices[i].position = D3DXVECTOR3(m_model[i].x, m_model[i].y, m_model[i].z);
	vertices[i].texture = D3DXVECTOR2(m_model[i].tu, m_model[i].tv);
	vertices[i].normal = D3DXVECTOR3(m_model[i].nx, m_model[i].ny, m_model[i].nz);

	indices[i] = i;
	}*/

	i = 0;
	vertices[i++].position = D3DXVECTOR3(-1, -1, -1);
	vertices[i++].position = D3DXVECTOR3(-1, -1, +1);
	vertices[i++].position = D3DXVECTOR3(-1, +1, -1);
	vertices[i++].position = D3DXVECTOR3(-1, +1, +1);
	vertices[i++].position = D3DXVECTOR3(+1, -1, -1);
	vertices[i++].position = D3DXVECTOR3(+1, -1, +1);
	vertices[i++].position = D3DXVECTOR3(+1, +1, -1);
	vertices[i++].position = D3DXVECTOR3(+1, +1, +1);

	i = 0;
	vertices[i++].normal = D3DXVECTOR3(0, 0, 0);
	vertices[i++].normal = D3DXVECTOR3(0, 0, 1);
	vertices[i++].normal = D3DXVECTOR3(0, 1, 0);
	vertices[i++].normal = D3DXVECTOR3(0, 1, 1);
	vertices[i++].normal = D3DXVECTOR3(1, 0, 0);
	vertices[i++].normal = D3DXVECTOR3(1, 0, 1);
	vertices[i++].normal = D3DXVECTOR3(1, 1, 0);
	vertices[i++].normal = D3DXVECTOR3(1, 1, 1);

	i = 0;
	indices[i++] = 2;
	indices[i++] = 6;
	indices[i++] = 0;

	indices[i++] = 0;
	indices[i++] = 6;
	indices[i++] = 4;

	indices[i++] = 4;
	indices[i++] = 6;
	indices[i++] = 5;

	indices[i++] = 5;
	indices[i++] = 6;
	indices[i++] = 7;

	indices[i++] = 5;
	indices[i++] = 7;
	indices[i++] = 1;

	indices[i++] = 1;
	indices[i++] = 7;
	indices[i++] = 3;
	

	return true;
}
