#include "pch.h"
#include "D3D11_BlendState.h"

D3D11_BlendState::D3D11_BlendState(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_BlendState::~D3D11_BlendState()
{
	Clear();
}

void D3D11_BlendState::Create(const bool _isBlend_Enabled, const D3D11_BLEND& _Src_Blend, const D3D11_BLEND& _Dst_Blend, const D3D11_BLEND_OP& _Blend_Op, const D3D11_BLEND& _Src_Blend_Alpha, const D3D11_BLEND& _Dst_Blend_Alpha, const D3D11_BLEND_OP& _Blend_Op_Alpha, const float& _Factor, const D3D11_COLOR_WRITE_ENABLE& _Color_Mask)
{
	D3D11_BLEND_DESC Desc;
	ZeroMemory(&Desc, sizeof(D3D11_BLEND_DESC));
	Desc.AlphaToCoverageEnable = FALSE;								// 폴리곤 내부의 Alpha의 안티앨리어싱 경계를 삭제할 수 있다. (대신 날카로워진다. 잔디, 철조망 등 jaggy현상)
	Desc.IndependentBlendEnable = FALSE;							// 8개의 RenderTarget을 독립적으로 다르게 설정할 것인지.

	Desc.RenderTarget[0].BlendEnable = _isBlend_Enabled;			// AlphaToCoverageEnable(경계삭제)와 다르게 배경색과 섞여들어감. (Alpha 혼합)
	Desc.RenderTarget[0].SrcBlend = _Src_Blend;						// 원본의 색 (배경색)
	Desc.RenderTarget[0].DestBlend = _Dst_Blend;					// 원본의 Alpha값의 역(목적지 : Texture)
	Desc.RenderTarget[0].BlendOp = _Blend_Op;						// 혼합 방법

	Desc.RenderTarget[0].SrcBlendAlpha = _Src_Blend_Alpha;			// 혼합 공식
	Desc.RenderTarget[0].DestBlendAlpha = _Dst_Blend_Alpha;			// 혼합 공식
	Desc.RenderTarget[0].BlendOpAlpha = _Blend_Op_Alpha;			// 혼합 공식
	Desc.RenderTarget[0].RenderTargetWriteMask = _Color_Mask;		// Mask : 특정 비트값을 가지는 이진수의 나열

	m_BlendFactor = _Factor;

	auto Hr = m_pDevice->CreateBlendState(&Desc, &m_pBlendState);
	assert(SUCCEEDED(Hr));
}

void D3D11_BlendState::Clear()
{
	SAFE_RELEASE(m_pBlendState);

	m_BlendFactor = static_cast<float>(NULL);
	m_SampleMask = 0xffffffff;
}
