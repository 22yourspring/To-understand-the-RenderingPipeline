#pragma once
class D3D11_Camera final
{
public:
	D3D11_Camera();
	~D3D11_Camera() = default;

private:
	D3DXMATRIX		m_View;
	D3DXMATRIX		m_Projection;

public:
	static const D3DXVECTOR3 LocalVector;
	static const D3DXVECTOR3 ForwardVector;
	static const D3DXVECTOR3 UpVector;

public:
	auto	GetViewMatrix() const -> const D3DXMATRIX& { return m_View; }
	auto	GetProjectionMatrix() const -> const D3DXMATRIX& { return m_Projection; }

public:
	void Update();

private:
	void UpdateViewMatrix();
	void UpdateProjectionMatrix();
};

