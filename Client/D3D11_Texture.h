#pragma once
class D3D11_Texture final
{
public:
	D3D11_Texture(class Graphics* pGraphics);
	~D3D11_Texture();

private:
	mutable ID3D11Device*				m_pDevice = nullptr;
	mutable ID3D11ShaderResourceView*	m_pShaderResourceView = nullptr;

public:
	ID3D11ShaderResourceView*& GetResource() const { return m_pShaderResourceView; }

	void Create(const std::string& _Path);
	void Clear();
};

