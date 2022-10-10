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
	Desc.AlphaToCoverageEnable = FALSE;								// ������ ������ Alpha�� ��Ƽ�ٸ���� ��踦 ������ �� �ִ�. (��� ��ī�ο�����. �ܵ�, ö���� �� jaggy����)
	Desc.IndependentBlendEnable = FALSE;							// 8���� RenderTarget�� ���������� �ٸ��� ������ ������.

	Desc.RenderTarget[0].BlendEnable = _isBlend_Enabled;			// AlphaToCoverageEnable(������)�� �ٸ��� ������ ������. (Alpha ȥ��)
	Desc.RenderTarget[0].SrcBlend = _Src_Blend;						// ������ �� (����)
	Desc.RenderTarget[0].DestBlend = _Dst_Blend;					// ������ Alpha���� ��(������ : Texture)
	Desc.RenderTarget[0].BlendOp = _Blend_Op;						// ȥ�� ���

	Desc.RenderTarget[0].SrcBlendAlpha = _Src_Blend_Alpha;			// ȥ�� ����
	Desc.RenderTarget[0].DestBlendAlpha = _Dst_Blend_Alpha;			// ȥ�� ����
	Desc.RenderTarget[0].BlendOpAlpha = _Blend_Op_Alpha;			// ȥ�� ����
	Desc.RenderTarget[0].RenderTargetWriteMask = _Color_Mask;		// Mask : Ư�� ��Ʈ���� ������ �������� ����

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
