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

	Desc.Filter = _Filter;								// Image�� Ȯ��, ���, Mipmap�� �Ͼ �� ����

	Desc.AddressU = _Address_Mode;						// UV��ǥ. x�� �þ�� ��
	Desc.AddressV = _Address_Mode;						// UV��ǥ. y�� �þ�� ��
	Desc.AddressW = _Address_Mode;						// �� �κ��� ������ �������� �þ�� ��

	Desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;		// ���� Sampling �� �����Ϳ� ��

	Desc.MaxAnisotropy = 16;							// ���漺 ���͸� (ȸ���Ǵ� �̹����� �ϱ׷��� �� ǥ�� ���)

	Desc.BorderColor[0] = 0.f;							// �ܰ����� ������� �� ����	R
	Desc.BorderColor[1] = 0.f;							// �ܰ����� ������� �� ����	G
	Desc.BorderColor[2] = 0.f;							// �ܰ����� ������� �� ����	B
	Desc.BorderColor[3] = 0.f;							// �ܰ����� ������� �� ����	A

	Desc.MinLOD = std::numeric_limits<float>::min();
	Desc.MaxLOD = std::numeric_limits<float>::max();
	Desc.MipLODBias = 0.f;								// Minmap Index�� �߰��Ǵ� offset ����

	auto Hr = m_pDevice->CreateSamplerState(&Desc, &m_pSamplerState);
	assert(SUCCEEDED(Hr));
}

void D3D11_SamplerState::Clear()
{
	SAFE_RELEASE(m_pSamplerState);
}
