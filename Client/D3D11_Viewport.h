#pragma once
class D3D11_Viewport final
{
public:
	D3D11_Viewport(const float& _Left = 0.f, const float& _Top = 0.f, const float& _Width = 0.f, const float& _Height = 0.f, const float& _MinDepth = 0.f, const float& _MaxDepth = 0.f);
	D3D11_Viewport(const D3D11_Viewport& _rhs);
	~D3D11_Viewport() = default;

private:
	float m_Left = 0.f;
	float m_Top = 0.f;
	float m_Width = 0.f;
	float m_Height = 0.f;
	float m_MinDepth = 0.f;
	float m_MaxDepth = 0.f;

public:
	static const D3D11_Viewport	Undefined_Viewport;

private:
	D3D11_VIEWPORT	D3D11Viewport = {};

public:
	const D3D11_VIEWPORT& GetViewport() const { return D3D11Viewport; }

public:
	void SetLeft(const float& _Value)		{ m_Left = _Value;			D3D11Viewport.TopLeftX = _Value; }
	void SetTop(const float& _Value)		{ m_Top = _Value;			D3D11Viewport.TopLeftY = _Value; }
	void SetWidth(const float& _Value)		{ m_Width = _Value;			D3D11Viewport.Width = _Value; }
	void SetHeight(const float& _Value)		{ m_Height = _Value;		D3D11Viewport.Height = _Value; }
	void SetMinDepth(const float& _Value)	{ m_MinDepth = _Value;		D3D11Viewport.MinDepth = _Value; }
	void SetMaxDepth(const float& _Value)	{ m_MaxDepth = _Value;		D3D11Viewport.MaxDepth = _Value; }

	void SetValue(const float& _Left, const float& _Top, const float& _Width, const float& _Height, const float& _MinDepth, const float& _MaxDepth);

public:
	inline bool operator == (const D3D11_Viewport& _rhs) const;
	inline bool operator != (const D3D11_Viewport& _rhs) const;

public:
	inline bool isDefined() const;
	auto AspectRatio() const { return m_Width / m_Height; }
};

