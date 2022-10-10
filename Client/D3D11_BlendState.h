#pragma once
class D3D11_BlendState final
{
public:
	D3D11_BlendState(class Graphics* pGraphics);
	~D3D11_BlendState();

private:
	ID3D11Device* m_pDevice = nullptr;
	ID3D11BlendState* m_pBlendState = nullptr;

private:
	mutable float	m_BlendFactor = 0.f;
	UINT	m_SampleMask = 0xffffffff;

public:
	ID3D11BlendState* GetResource() const { return m_pBlendState; }
	float& GetBlendFactor()	const { return m_BlendFactor; }
	const UINT GetSampleMask()	const { return m_SampleMask; }

public:
	void Create(const bool _isBlend_Enabled, const D3D11_BLEND& _Src_Blend = D3D11_BLEND_SRC_ALPHA, const D3D11_BLEND& _Dst_Blend = D3D11_BLEND_INV_SRC_ALPHA, const D3D11_BLEND_OP& _Blend_Op = D3D11_BLEND_OP_ADD, const D3D11_BLEND& _Src_Blend_Alpha = D3D11_BLEND_ONE, const D3D11_BLEND& _Dst_Blend_Alpha = D3D11_BLEND_ZERO, const D3D11_BLEND_OP& _Blend_Op_Alpha = D3D11_BLEND_OP_ADD, const float& _Factor = 0.f, const D3D11_COLOR_WRITE_ENABLE& _Color_Mask = D3D11_COLOR_WRITE_ENABLE_ALL);
	void Clear();
};

