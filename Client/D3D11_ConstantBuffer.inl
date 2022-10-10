#include "D3D11_ConstantBuffer.h"

template<typename T>
inline void D3D11_ConstantBuffer::Create(const D3D11_USAGE& _Usage)
{
	D3D11_BUFFER_DESC Desc;
	ZeroMemory(&Desc, sizeof(D3D11_BUFFER_DESC));
	Desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	Desc.ByteWidth = sizeof(T);
	Desc.Usage = _Usage;

	switch (Desc.Usage)
	{
	case D3D11_USAGE_DEFAULT:
	case D3D11_USAGE_IMMUTABLE:	Desc.CPUAccessFlags = NULL; break;
	case D3D11_USAGE_DYNAMIC:	Desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; break;
	case D3D11_USAGE_STAGING:	Desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE; break;
	}

	auto Hr = m_pDevice->CreateBuffer(&Desc, nullptr, &m_pBuffer);
	assert(SUCCEEDED(Hr));
}

template<typename T>
inline auto D3D11_ConstantBuffer::Map() -> T*
{
	D3D11_MAPPED_SUBRESOURCE Mapped_Resource;

	auto Hr = m_pDeviceContext->Map(m_pBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &Mapped_Resource);

	return static_cast<T*>(Mapped_Resource.pData);
}
