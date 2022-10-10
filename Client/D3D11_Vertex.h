#pragma once

typedef struct D3D11_VertexColor final
{
	D3D11_VertexColor()
		: Position()
		, Color()
	{}

	D3D11_VertexColor(const D3DXVECTOR3& _Position, const D3DXCOLOR& _Color)
		: Position(_Position)
		, Color(_Color)
	{}

	D3DXVECTOR3		Position;
	D3DXCOLOR		Color;

	static D3D11_INPUT_ELEMENT_DESC Descs[];
	static const UINT Count = 2;
}_Vertex;

typedef struct D3D11_VertexTexture final
{
	D3D11_VertexTexture()
		: Position()
		, UV()
	{}

	D3D11_VertexTexture(const D3DXVECTOR3& _Position, const D3DXVECTOR2& _UV)
		: Position(_Position)
		, UV(_UV)
	{}

	D3DXVECTOR3		Position;
	D3DXVECTOR2		UV;			// texcoord	: Texture Coordinate

	static D3D11_INPUT_ELEMENT_DESC Descs[];
	static const UINT Count = 2;
}_Texture;