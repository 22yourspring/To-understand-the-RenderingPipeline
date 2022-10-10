#include "pch.h"
#include "Geometry_Generator.h"

void Geometry_Generator::CreateQuad(D3D11_Geometry<struct D3D11_VertexTexture>& _Geometry)
{
	_Geometry.AddVertex(D3D11_VertexTexture(D3DXVECTOR3(-0.5f, -0.5f, 0.f), D3DXVECTOR2(0.f, 1.f)));
	_Geometry.AddVertex(D3D11_VertexTexture(D3DXVECTOR3(-0.5f, +0.5f, 0.f), D3DXVECTOR2(0.f, 0.f)));
	_Geometry.AddVertex(D3D11_VertexTexture(D3DXVECTOR3(+0.5f, -0.5f, 0.f), D3DXVECTOR2(1.f, 1.f)));
	_Geometry.AddVertex(D3D11_VertexTexture(D3DXVECTOR3(+0.5f, +0.5f, 0.f), D3DXVECTOR2(1.f, 0.f)));

	_Geometry.AddIndex(0);	_Geometry.AddIndex(1);	_Geometry.AddIndex(2);
	_Geometry.AddIndex(2);	_Geometry.AddIndex(1);	_Geometry.AddIndex(3);
}
