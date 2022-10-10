#include "pch.h"
#include "D3D11_Texture.h"

D3D11_Texture::D3D11_Texture(Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_Texture::~D3D11_Texture()
{
	Clear();
}

void D3D11_Texture::Create(const std::string& _Path)
{
	auto Hr = D3DX11CreateShaderResourceViewFromFileA(m_pDevice, _Path.c_str(), nullptr, nullptr, &m_pShaderResourceView, nullptr);
	assert(SUCCEEDED(Hr));
}

void D3D11_Texture::Clear()
{
	SAFE_RELEASE(m_pShaderResourceView);
}
