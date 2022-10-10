#include "pch.h"
#include "D3D11_InputLayout.h"

D3D11_InputLayout::D3D11_InputLayout(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_InputLayout::~D3D11_InputLayout()
{
	Clear();
}

void D3D11_InputLayout::Create(D3D11_INPUT_ELEMENT_DESC* _Descs, const UINT& _Count, ID3DBlob* _pBlob)
{
	assert(_Descs && _Count && _pBlob);

	auto Hr = m_pDevice->CreateInputLayout(_Descs, 2, _pBlob->GetBufferPointer(), _pBlob->GetBufferSize(), &m_pInputLayout);
	assert(SUCCEEDED(Hr));
}

void D3D11_InputLayout::Clear()
{
	SAFE_RELEASE(m_pInputLayout);
}
