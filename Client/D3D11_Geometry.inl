#include "D3D11_Geometry.h"

template<class T>
inline D3D11_Geometry<T>::~D3D11_Geometry()
{
	Clear();
}

template<class T>
inline auto D3D11_Geometry<T>::GetVertices(const UINT& _Offset, const UINT& _Count) -> const std::vector<T>
{
	std::vector<T> Sub_vertices;

	auto First = m_Vertices.begin() + _Offset;
	auto Last = First + _Count;

	Sub_vertices.assign(First, Last);

	return Sub_vertices;
}

template<class T>
inline void D3D11_Geometry<T>::AddVertex(const T& _Vertex)
{
	m_Vertices.emplace_back(_Vertex);
}

template<class T>
inline void D3D11_Geometry<T>::AddVertices(const std::vector<T>& _Vertices)
{
	this->m_Vertices.insert(this->m_Vertices.end(), _Vertices.begin(), _Vertices.end());
}

template<class T>
inline void D3D11_Geometry<T>::SetVertices(const std::vector<T>& _Vertices)
{
	this->m_Vertices.clear();
	this->m_Vertices.shrink_to_fit();
	this->m_Vertices = _Vertices;
}

template<class T>
inline auto D3D11_Geometry<T>::GetIndices(const UINT& _Offset, const UINT& _Count) -> const std::vector<UINT>
{
	std::vector<T> Sub_Indices;

	auto First = m_Indices.begin() + _Offset;
	auto Last = First + _Count;

	Sub_Indices.assign(First, Last);

	return Sub_Indices;
}

template<class T>
inline void D3D11_Geometry<T>::AddIndex(const UINT& _Index)
{
	m_Indices.emplace_back(_Index);
}

template<class T>
inline void D3D11_Geometry<T>::AddIndices(const std::vector<UINT>& _Indices)
{
	this->m_Indices.insert(this->m_Indices.end(), _Indices.begin(), _Indices.end());
}

template<class T>
inline void D3D11_Geometry<T>::SetIndices(const std::vector<UINT>& _Indices)
{
	this->m_Indices.clear();
	this->m_Indices.shrink_to_fit();
	this->m_Indices = _Indices;
}

template<class T>
inline void D3D11_Geometry<T>::Clear()
{
	m_Vertices.clear();
	m_Vertices.shrink_to_fit();

	m_Indices.clear();
	m_Indices.shrink_to_fit();
}
