#include "pch.h"
#include "D3D11_ConstantBuffer.h"

D3D11_ConstantBuffer::D3D11_ConstantBuffer(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
	m_pDeviceContext = pGraphics->GetDeviceContext();
}

D3D11_ConstantBuffer::~D3D11_ConstantBuffer()
{
	Clear();
}

void D3D11_ConstantBuffer::Clear()
{
	SAFE_RELEASE(m_pBuffer);
}

bool D3D11_ConstantBuffer::Unmap()
{
	if (!m_pDevice || !m_pDeviceContext || !m_pBuffer)
		return false;

	m_pDeviceContext->Unmap(m_pBuffer, NULL);

	return true;
}
