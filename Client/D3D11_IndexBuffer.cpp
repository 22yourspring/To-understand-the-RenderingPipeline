#include "pch.h"
#include "D3D11_IndexBuffer.h"

D3D11_IndexBuffer::D3D11_IndexBuffer(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_IndexBuffer::~D3D11_IndexBuffer()
{
	Clear();
}

void D3D11_IndexBuffer::Create(const std::vector<UINT>& _Indices, const D3D11_USAGE& _Usage)
{
	m_Stride = sizeof(UINT);
	m_Count = static_cast<UINT>(_Indices.size());

	D3D11_BUFFER_DESC Desc;
	ZeroMemory(&Desc, sizeof(D3D11_BUFFER_DESC));
	Desc.Usage = D3D11_USAGE_IMMUTABLE;
	Desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	Desc.ByteWidth = m_Stride * m_Count;

	D3D11_SUBRESOURCE_DATA	SubData;
	ZeroMemory(&SubData, sizeof(D3D11_SUBRESOURCE_DATA));
	SubData.pSysMem = _Indices.data();

	auto Hr = m_pDevice->CreateBuffer(&Desc, &SubData, &m_pBuffer);
	assert(SUCCEEDED(Hr));
}

void D3D11_IndexBuffer::Clear()
{
	SAFE_RELEASE(m_pBuffer);
	
	m_Stride = NULL;
	m_Offset = NULL;
	m_Count = NULL;
}
