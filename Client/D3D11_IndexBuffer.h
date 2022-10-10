#pragma once
class D3D11_IndexBuffer final
{
public:
	D3D11_IndexBuffer(class Graphics* pGraphics);
	~D3D11_IndexBuffer();

private:
	mutable ID3D11Device*	m_pDevice = nullptr;
	mutable ID3D11Buffer*	m_pBuffer = nullptr;

	UINT			m_Stride = 0;
	UINT			m_Offset = 0;
	UINT			m_Count = 0;

public:
	ID3D11Buffer*& GetResource() const { return m_pBuffer; }
	const UINT& GetStride() const { return m_Stride; }
	const UINT& GetOffset() const { return m_Offset; }
	const UINT& GetCount() const { return m_Count; }

	void Create(const std::vector<UINT>& _Indices, const D3D11_USAGE& _Usage = D3D11_USAGE_IMMUTABLE);
	void Clear();
};

