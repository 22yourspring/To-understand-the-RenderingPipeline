#pragma once

typedef struct __tagTransform
{
	D3DXMATRIX		World;
	D3DXMATRIX		View;
	D3DXMATRIX		Projection;
}Transform_Data, __Transform;

class D3D11_Interface final
{
public:
	D3D11_Interface();
	~D3D11_Interface();

private:
	class Graphics*							m_pGraphics = nullptr;
	
	D3D11_VertexBuffer*						m_pVertexBuffer = nullptr;
	D3D11_IndexBuffer*						m_pIndexBuffer = nullptr;
	D3D11_InputLayout*						m_pInputLayout = nullptr;

	D3D11_Shader*							m_pVertexShader = nullptr;
	D3D11_Shader*							m_pPixelShader = nullptr;

	D3D11_ConstantBuffer*					GPU_Buffer = nullptr;		// Constant Buffer
	D3D11_RasterizerState*					m_pRasterizer = nullptr;

	D3D11_Texture*							m_pTexture = nullptr;		// Resource View
	
	D3D11_SamplerState*						m_pSamplerState = nullptr;
	D3D11_BlendState*						m_pBlendState = nullptr;
	
	D3DXMATRIX								World;
	class D3D11_Camera*						m_pD3D11_Camera;
	

public:
	void update();
	void render();
};

