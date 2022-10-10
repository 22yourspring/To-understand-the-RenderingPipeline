#include "pch.h"
#include "D3D11_Viewport.h"

const D3D11_Viewport D3D11_Viewport::Undefined_Viewport = {};

D3D11_Viewport::D3D11_Viewport(const float& _Left, const float& _Top, const float& _Width, const float& _Height, const float& _MinDepth, const float& _MaxDepth)
	: m_Left(_Left)
	, m_Top(_Top)
	, m_Width(_Width)
	, m_Height(_Height)
	, m_MinDepth(_MinDepth)
	, m_MaxDepth(_MaxDepth)
{
	D3D11Viewport.TopLeftX = _Left;
	D3D11Viewport.TopLeftY = _Top;
	D3D11Viewport.Width = _Width;
	D3D11Viewport.Height = _Height;
	D3D11Viewport.MinDepth = _MinDepth;
	D3D11Viewport.MaxDepth = _MaxDepth;
}

D3D11_Viewport::D3D11_Viewport(const D3D11_Viewport& _rhs)
	: m_Left(_rhs.m_Left)
	, m_Top(_rhs.m_Top)
	, m_Width(_rhs.m_Width)
	, m_Height(_rhs.m_Height)
	, m_MinDepth(_rhs.m_MinDepth)
	, m_MaxDepth(_rhs.m_MaxDepth)
{
	D3D11Viewport.TopLeftX = _rhs.m_Left;
	D3D11Viewport.TopLeftY = _rhs.m_Top;
	D3D11Viewport.Width = _rhs.m_Width;
	D3D11Viewport.Height = _rhs.m_Height;
	D3D11Viewport.MinDepth = _rhs.m_MinDepth;
	D3D11Viewport.MaxDepth = _rhs.m_MaxDepth;
}

void D3D11_Viewport::SetValue(const float& _Left, const float& _Top, const float& _Width, const float& _Height, const float& _MinDepth, const float& _MaxDepth)
{
	SetLeft(_Left);
	SetTop(_Top);
	SetWidth(_Width);
	SetHeight(_Height);
	SetMinDepth(_MinDepth);
	SetMaxDepth(_MaxDepth);
}

inline bool D3D11_Viewport::operator==(const D3D11_Viewport& _rhs) const
{
	return m_Left == _rhs.m_Left && m_Top == _rhs.m_Top && m_Width == _rhs.m_Width && m_Height == _rhs.m_Height && m_MinDepth == _rhs.m_MinDepth && m_MaxDepth == _rhs.m_MaxDepth;
}

inline bool D3D11_Viewport::operator!=(const D3D11_Viewport& _rhs) const
{
	return !(*this == _rhs);
}

inline bool D3D11_Viewport::isDefined() const
{
	return m_Left != 0.f || m_Top != 0.f || m_Width != 0.f || m_Height != 0.f || m_MinDepth != 0.f || m_MaxDepth != 0.f;
}
