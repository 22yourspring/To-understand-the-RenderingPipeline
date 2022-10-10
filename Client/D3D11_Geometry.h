#pragma once

template <class T>
class D3D11_Geometry
{
public:
	D3D11_Geometry() = default;
	virtual ~D3D11_Geometry();

protected:
	std::vector<T>		m_Vertices;
	std::vector<UINT>	m_Indices;

public:
	// Vertex
	auto GetVertexCount() const { return static_cast<UINT>(m_Vertices.size()); }
	auto GetVertexByteWidth() const { return GetVertexCount() * sizeof(T); }
	auto GetVertexPointer() const { return m_Vertices.data(); }
	auto GetVertices() const -> const std::vector<T>& { return m_Vertices; }
	auto GetVertices(const UINT& _Offset, const UINT& _Count) -> const std::vector<T>;

	void AddVertex(const T& _Vertex);
	void AddVertices(const std::vector<T>& _Vertices);
	void SetVertices(const std::vector<T>& _Vertices);

	// Index
	auto GetIndexCount() const { return static_cast<UINT>(m_Indices.size()); }
	auto GetIndexByteWidth() const { return GetIndexCount() * sizeof(UINT); }
	auto GetIndexPointer() const { return m_Indices.data(); }
	auto GetIndices() const -> const std::vector<UINT>& { return m_Indices; }
	auto GetIndices(const UINT& _Offset, const UINT& _Count) -> const std::vector<UINT>;

	void AddIndex(const UINT& _Index);
	void AddIndices(const std::vector<UINT>& _Indices);
	void SetIndices(const std::vector<UINT>& _Indices);

	// MICS
	void Clear();
};

#include "D3D11_Geometry.inl"