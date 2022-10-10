#pragma once
class D3D11_SamplerState final
{
public:
	D3D11_SamplerState(class Graphics* pGraphics);
	~D3D11_SamplerState();

private:
	mutable ID3D11Device*			m_pDevice = nullptr;
	mutable ID3D11SamplerState*		m_pSamplerState = nullptr;

public:
	ID3D11SamplerState*& GetResource() const { return m_pSamplerState; }

	void Create(const D3D11_FILTER& _Filter, const D3D11_TEXTURE_ADDRESS_MODE& _Address_Mode);
	void Clear();
};

