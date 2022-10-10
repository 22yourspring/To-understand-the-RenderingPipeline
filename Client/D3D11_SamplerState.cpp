#include "pch.h"
#include "D3D11_SamplerState.h"

D3D11_SamplerState::D3D11_SamplerState(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_SamplerState::~D3D11_SamplerState()
{
	Clear();
}

void D3D11_SamplerState::Create(const D3D11_FILTER& _Filter, const D3D11_TEXTURE_ADDRESS_MODE& _Address_Mode)
{
	D3D11_SAMPLER_DESC Desc;
	ZeroMemory(&Desc, sizeof(D3D11_SAMPLER_DESC));

	Desc.Filter = _Filter;								// Image가 확대, 축소, Mipmap이 일어날 때 보정

	Desc.AddressU = _Address_Mode;						// UV좌표. x가 늘어났을 때
	Desc.AddressV = _Address_Mode;						// UV좌표. y가 늘어났을 때
	Desc.AddressW = _Address_Mode;						// 두 부분을 제외한 나머지가 늘어났을 때

	Desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;		// 이전 Sampling 된 데이터와 비교

	Desc.MaxAnisotropy = 16;							// 비등방성 필터링 (회전되는 이미지가 일그러질 때 표현 방법)

	Desc.BorderColor[0] = 0.f;							// 외곽선의 빈공간에 들어갈 색상	R
	Desc.BorderColor[1] = 0.f;							// 외곽선의 빈공간에 들어갈 색상	G
	Desc.BorderColor[2] = 0.f;							// 외곽선의 빈공간에 들어갈 색상	B
	Desc.BorderColor[3] = 0.f;							// 외곽선의 빈공간에 들어갈 색상	A

	Desc.MinLOD = std::numeric_limits<float>::min();
	Desc.MaxLOD = std::numeric_limits<float>::max();
	Desc.MipLODBias = 0.f;								// Minmap Index에 추가되는 offset 정보

	auto Hr = m_pDevice->CreateSamplerState(&Desc, &m_pSamplerState);
	assert(SUCCEEDED(Hr));
}

void D3D11_SamplerState::Clear()
{
	SAFE_RELEASE(m_pSamplerState);
}
