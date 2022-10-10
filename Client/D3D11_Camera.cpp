#include "pch.h"
#include "D3D11_Camera.h"

const D3DXVECTOR3 D3D11_Camera::LocalVector = { 0, 0, 0 };
const D3DXVECTOR3 D3D11_Camera::ForwardVector = { 0, 0, 1 };
const D3DXVECTOR3 D3D11_Camera::UpVector = { 0, 1, 0 };

D3D11_Camera::D3D11_Camera()
{
	D3DXMatrixIdentity(&m_View);
	D3DXMatrixIdentity(&m_Projection);

	UpdateViewMatrix();
	UpdateProjectionMatrix();
}

void D3D11_Camera::Update()
{
	UpdateViewMatrix();
	UpdateProjectionMatrix();
}

void D3D11_Camera::UpdateViewMatrix()
{
	D3DXMatrixLookAtLH(&m_View, &LocalVector, &ForwardVector, &UpVector);
}

void D3D11_Camera::UpdateProjectionMatrix()
{
	D3DXMatrixOrthoLH(&m_Projection, Settings::GetInst().GetWidth(), Settings::GetInst().GetHeight(), 0.f, 1.f);
}
