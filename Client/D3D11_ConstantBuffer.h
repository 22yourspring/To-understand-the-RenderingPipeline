#pragma once
class D3D11_ConstantBuffer final
{
public:
	D3D11_ConstantBuffer(class Graphics* pGraphics);
	~D3D11_ConstantBuffer();

private:
	mutable ID3D11Device*			m_pDevice = nullptr;
	mutable ID3D11DeviceContext*	m_pDeviceContext = nullptr;
	mutable ID3D11Buffer*			m_pBuffer = nullptr;

public:
	ID3D11Buffer*& GetResource() const { return m_pBuffer; }

	template <typename T>
	void Create(const D3D11_USAGE& _Usage = D3D11_USAGE_DYNAMIC);	
	void Clear();

	template <typename T>
	auto Map()->T*;
	bool Unmap();
};

#include "D3D11_ConstantBuffer.inl"