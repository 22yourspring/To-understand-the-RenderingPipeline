#pragma once

struct D3D11_PipelineState final
{
	D3D11_InputLayout*			pInputLayout = nullptr;
	D3D11_PRIMITIVE_TOPOLOGY	Primitive_topology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	D3D11_Shader*				pVertexShader = nullptr;
	D3D11_Shader*				pPixelShader = nullptr;

	D3D11_RasterizerState*		pRasterizer = nullptr;

	D3D11_BlendState*			pBlendState = nullptr;
};

class D3D11_Pipeline final
{
public:
	D3D11_Pipeline(class Graphics* pGraphics);
	~D3D11_Pipeline();

private:
	ID3D11DeviceContext* m_pDeviceContext = nullptr;

public:
	void SetVertexBuffer(const class VertexBuffer* _pBuffer);
	void SetIndexBuffer(const class IndexBuffer* _pBuffer);

	void SetConstantBuffer(const UINT& _Slot, const ShaderScope& _State, const D3D11_ConstantBuffer* _pBuffer);
	void SetShaderResource(const UINT& _Slot, const ShaderScope& _State, const D3D11_Texture* _pResource);
	void SetSamplerState(const UINT& _Slot, const ShaderScope& _State, const D3D11_SamplerState* _pSamplerState);	

public:
	void Draw(const UINT& _Vertex_Count, const UINT& _Vertex_Offset = 0);
	void DrawIndexed(const UINT& _Index_Count, const UINT& _Index_Offset = 0, const UINT& _Vertex_Offset = 0);

public:
	void Begin(const D3D11_PipelineState& _Pipeline_State);
	void End();
};

