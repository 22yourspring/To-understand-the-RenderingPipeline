#pragma once
class D3D11_RasterizerState final
{
public:
	D3D11_RasterizerState(class Graphics* pGraphics);
	~D3D11_RasterizerState();

private:
	ID3D11Device*			m_pDevice = nullptr;
	ID3D11RasterizerState*	m_pRasterizerState = nullptr;

public:
	auto GetResource() const { return m_pRasterizerState; }

	void Create(const D3D11_FILL_MODE& _FillMode, const D3D11_CULL_MODE& _CullMode);
	void Clear();
};

