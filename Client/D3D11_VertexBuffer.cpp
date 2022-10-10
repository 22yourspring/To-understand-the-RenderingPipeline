#include "pch.h"
#include "D3D11_VertexBuffer.h"

D3D11_VertexBuffer::D3D11_VertexBuffer(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_VertexBuffer::~D3D11_VertexBuffer()
{
	Clear();
}

void D3D11_VertexBuffer::Clear()
{
	SAFE_RELEASE(m_pBuffer);

	m_Stride = NULL;
	m_Offset = NULL;
	m_Count = NULL;
}
