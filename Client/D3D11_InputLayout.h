#pragma once
class D3D11_InputLayout final
{
public:
	D3D11_InputLayout(class Graphics* pGraphics);
	~D3D11_InputLayout();

private:
	mutable ID3D11Device*		m_pDevice = nullptr;
	mutable ID3D11InputLayout*	m_pInputLayout = nullptr;

public:
	ID3D11InputLayout*& GetResource() const { return m_pInputLayout; }

	void Create(D3D11_INPUT_ELEMENT_DESC* _Descs, const UINT& _Count, ID3DBlob* _pBlob);
	void Clear();
};

