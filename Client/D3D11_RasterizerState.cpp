#include "pch.h"
#include "D3D11_RasterizerState.h"

D3D11_RasterizerState::D3D11_RasterizerState(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_RasterizerState::~D3D11_RasterizerState()
{
	Clear();
}

void D3D11_RasterizerState::Create(const D3D11_FILL_MODE& _FillMode, const D3D11_CULL_MODE& _CullMode)
{
	D3D11_RASTERIZER_DESC Desc;
	ZeroMemory(&Desc, sizeof(D3D11_RASTERIZER_DESC));
	Desc.FillMode = _FillMode;
	Desc.CullMode = _CullMode;
	Desc.FrontCounterClockwise = false;

	auto Hr = m_pDevice->CreateRasterizerState(&Desc, &m_pRasterizerState);
	assert(SUCCEEDED(Hr));
}

void D3D11_RasterizerState::Clear()
{
	SAFE_RELEASE(m_pRasterizerState);
}
