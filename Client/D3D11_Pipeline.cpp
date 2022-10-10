#include "pch.h"
#include "D3D11_Pipeline.h"

D3D11_Pipeline::D3D11_Pipeline(Graphics* pGraphics)
{
}

D3D11_Pipeline::~D3D11_Pipeline()
{
}

void D3D11_Pipeline::SetVertexBuffer(const VertexBuffer* _pBuffer)
{
}

void D3D11_Pipeline::SetIndexBuffer(const IndexBuffer* _pBuffer)
{
}

void D3D11_Pipeline::SetConstantBuffer(const UINT& _Slot, const ShaderScope& _State, const D3D11_ConstantBuffer* _pBuffer)
{
}

void D3D11_Pipeline::SetShaderResource(const UINT& _Slot, const ShaderScope& _State, const D3D11_Texture* _pResource)
{
}

void D3D11_Pipeline::SetSamplerState(const UINT& _Slot, const ShaderScope& _State, const D3D11_SamplerState* _pSamplerState)
{
}

void D3D11_Pipeline::Draw(const UINT& _Vertex_Count, const UINT& _Vertex_Offset)
{
}

void D3D11_Pipeline::DrawIndexed(const UINT& _Index_Count, const UINT& _Index_Offset, const UINT& _Vertex_Offset)
{
}

void D3D11_Pipeline::Begin(const D3D11_PipelineState& _Pipeline_State)
{
}

void D3D11_Pipeline::End()
{
}
