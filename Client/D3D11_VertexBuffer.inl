#include "D3D11_VertexBuffer.h"

template<typename T>
inline void D3D11_VertexBuffer::Create(const std::vector<T> _Vertices, const D3D11_USAGE& _Usage)
{
	m_Stride = sizeof(T);
	m_Count = static_cast<UINT>(_Vertices.size());
	
	D3D11_BUFFER_DESC Desc;
	ZeroMemory(&Desc, sizeof(D3D11_BUFFER_DESC));
	Desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	Desc.ByteWidth = m_Stride * m_Count;
	Desc.Usage = _Usage;
	
	switch (Desc.Usage)
	{
	case D3D11_USAGE_DEFAULT:
	case D3D11_USAGE_IMMUTABLE:	Desc.CPUAccessFlags = NULL; break;
	case D3D11_USAGE_DYNAMIC:	Desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; break;
	case D3D11_USAGE_STAGING:	Desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE; break;
	}

	D3D11_SUBRESOURCE_DATA Sub_Data;
	ZeroMemory(&Sub_Data, sizeof(D3D11_SUBRESOURCE_DATA));
	Sub_Data.pSysMem = _Vertices.data();

	auto Hr = m_pDevice->CreateBuffer(&Desc, &Sub_Data, &m_pBuffer);
	assert(SUCCEEDED(Hr));
}
