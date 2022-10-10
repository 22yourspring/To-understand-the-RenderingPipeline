#include "pch.h"
#include "D3D11_Interface.h"
#include "D3D11_Camera.h"

D3D11_Interface::D3D11_Interface()
{
	// Graphics Setting
	m_pGraphics = new Graphics();
	m_pGraphics->Initialize();
	m_pGraphics->CreateBuffer(static_cast<UINT>(Settings::GetInst().GetWidth()), static_cast<UINT>(Settings::GetInst().GetHeight()));

	// Geometry (Vertex, Index)
	D3D11_Geometry<D3D11_VertexTexture> Geometry;
	Geometry_Generator::CreateQuad(Geometry);

	// Create Vertex Buffer
	m_pVertexBuffer = new D3D11_VertexBuffer(m_pGraphics);
	m_pVertexBuffer->Create<D3D11_VertexTexture>(Geometry.GetVertices());

	// Index Buffer
	m_pIndexBuffer = new D3D11_IndexBuffer(m_pGraphics);
	m_pIndexBuffer->Create(Geometry.GetIndices());
	 
	// Vertex Shader
	m_pVertexShader = new D3D11_Shader(m_pGraphics);
	m_pVertexShader->Create(ShaderScope::VertexShader, "../_Asset/Shader/Texture.hlsl");

	// Pixel Shader
	m_pPixelShader = new D3D11_Shader(m_pGraphics);
	m_pPixelShader->Create(ShaderScope::PixelShader, "../_Asset/Shader/Texture.hlsl");

	// Input Layout
	m_pInputLayout = new D3D11_InputLayout(m_pGraphics);
	m_pInputLayout->Create(D3D11_VertexTexture::Descs, D3D11_VertexTexture::Count, m_pVertexShader->GetShaderBlob());

	// Create Constant Buffer
	GPU_Buffer = new D3D11_ConstantBuffer(m_pGraphics);
	GPU_Buffer->Create<__Transform>();

	// Create Rasterizer State
	m_pRasterizer = new D3D11_RasterizerState(m_pGraphics);
	m_pRasterizer->Create(D3D11_FILL_SOLID, D3D11_CULL_BACK);

	// Create Shader Resource View
	m_pTexture = new D3D11_Texture(m_pGraphics);
	m_pTexture->Create("../_Asset/Texture/tree.png");

	// Create Sampler State
	m_pSamplerState = new D3D11_SamplerState(m_pGraphics);
	m_pSamplerState->Create(D3D11_FILTER_MIN_MAG_MIP_LINEAR, D3D11_TEXTURE_ADDRESS_WRAP);

	// Create View Projection
	D3DXMatrixIdentity(&World);
	m_pD3D11_Camera = new D3D11_Camera;

	// Create World
	D3DXMatrixIdentity(&World);

	// World
	{
		D3DXMATRIX Scale;
		D3DXMatrixScaling(&Scale, 500, 500, 1);

		D3DXMATRIX Transform;
		D3DXMatrixTranslation(&Transform, 0, 0, 0);

		D3DXMATRIX Rotation;
		D3DXMatrixRotationZ(&Rotation, static_cast<float>(D3DXToRadian(45.)));

		World = Scale * /*Rotation **/ Transform;
	}
	// {
	// 	D3DXMatrixIdentity(&World);
	// 	m_pD3D11_Camera = new D3D11_Camera;
	// 
	// 	std::cout << "View Matrix" << std::endl;
	// 	std::cout << "\t" << m_View._11 << "\t" << m_View._12 << "\t" << m_View._13 << "\t" << m_View._14 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_View._21 << "\t" << m_View._22 << "\t" << m_View._23 << "\t" << m_View._24 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_View._31 << "\t" << m_View._32 << "\t" << m_View._33 << "\t" << m_View._34 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_View._41 << "\t" << m_View._42 << "\t" << m_View._43 << "\t" << m_View._44 << std::endl << std::endl << std::endl;
	// 
	// 
	// 	std::cout << "Projection Matrix" << std::endl;
	// 	std::cout << "\t" << m_Projection._11 << "\t" << m_Projection._12 << "\t" << m_Projection._13 << "\t" << m_Projection._14 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_Projection._21 << "\t" << m_Projection._22 << "\t" << m_Projection._23 << "\t" << m_Projection._24 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_Projection._31 << "\t" << m_Projection._32 << "\t" << m_Projection._33 << "\t" << m_Projection._34 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_Projection._41 << "\t" << m_Projection._42 << "\t" << m_Projection._43 << "\t" << m_Projection._44 << std::endl << std::endl << std::endl;
	// 
	// 	// World
	// 	D3DXMATRIX Scale;
	// 	D3DXMatrixScaling(&Scale, 500, 500, 1);
	// 
	// 	std::cout << "Scale Matrix" << std::endl;
	// 	std::cout << "\t" << Scale._11 << "\t" << Scale._12 << "\t" << Scale._13 << "\t" << Scale._14 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Scale._21 << "\t" << Scale._22 << "\t" << Scale._23 << "\t" << Scale._24 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Scale._31 << "\t" << Scale._32 << "\t" << Scale._33 << "\t" << Scale._34 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Scale._41 << "\t" << Scale._42 << "\t" << Scale._43 << "\t" << Scale._44 << std::endl << std::endl << std::endl;
	// 
	// 	D3DXMATRIX Transform;
	// 	D3DXMatrixTranslation(&Transform, 0, 0, 0);
	// 
	// 	std::cout << "Translation Matrix" << std::endl;
	// 	std::cout << "\t" << Transform._11 << "\t" << Transform._12 << "\t" << Transform._13 << "\t" << Transform._14 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Transform._21 << "\t" << Transform._22 << "\t" << Transform._23 << "\t" << Transform._24 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Transform._31 << "\t" << Transform._32 << "\t" << Transform._33 << "\t" << Transform._34 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Transform._41 << "\t" << Transform._42 << "\t" << Transform._43 << "\t" << Transform._44 << std::endl << std::endl << std::endl;
	// 
	// 	D3DXMATRIX Rotation;
	// 	D3DXMatrixRotationZ(&Rotation, static_cast<float>(D3DXToRadian(45.)));
	// 
	// 	std::cout << "Rotation Matrix" << std::endl;
	// 	std::cout << "\t" << Rotation._11 << "\t" << Rotation._12 << "\t" << Rotation._13 << "\t" << Rotation._14 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Rotation._21 << "\t" << Rotation._22 << "\t" << Rotation._23 << "\t" << Rotation._24 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Rotation._31 << "\t" << Rotation._32 << "\t" << Rotation._33 << "\t" << Rotation._34 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << Rotation._41 << "\t" << Rotation._42 << "\t" << Rotation._43 << "\t" << Rotation._44 << std::endl << std::endl << std::endl;
	// 
	// 	// 크 자 이 공 부
	// 	// 기 전 동 전 모
	// 	m_World = Scale * /*Rotation **/ Transform;
	// 
	// 	std::cout << "World Matrix" << std::endl;
	// 	std::cout << "\t" << m_World._11 << "\t" << m_World._12 << "\t" << m_World._13 << "\t" << m_World._14 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_World._21 << "\t" << m_World._22 << "\t" << m_World._23 << "\t" << m_World._24 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_World._31 << "\t" << m_World._32 << "\t" << m_World._33 << "\t" << m_World._34 << std::endl << std::endl << std::endl;
	// 	std::cout << "\t" << m_World._41 << "\t" << m_World._42 << "\t" << m_World._43 << "\t" << m_World._44 << std::endl << std::endl << std::endl;
	// }
	
	// Create Blend State
	m_pBlendState = new D3D11_BlendState(m_pGraphics);
	m_pBlendState->Create(true);
}

D3D11_Interface::~D3D11_Interface()
{
	SAFE_DELETE(m_pD3D11_Camera);
	SAFE_DELETE(m_pBlendState);
	SAFE_DELETE(m_pSamplerState);
	SAFE_DELETE(m_pTexture);
	SAFE_DELETE(m_pRasterizer);
	SAFE_DELETE(GPU_Buffer);
	SAFE_DELETE(m_pInputLayout);
	SAFE_DELETE(m_pPixelShader);
	SAFE_DELETE(m_pVertexShader);
	SAFE_DELETE(m_pIndexBuffer);
	SAFE_DELETE(m_pVertexBuffer);
	SAFE_DELETE(m_pGraphics);
}

void D3D11_Interface::update()
{
	m_pD3D11_Camera->Update();

	auto Buffer = GPU_Buffer->Map<__Transform>();
	{
		D3DXMatrixTranspose(&Buffer->World, &World);
		D3DXMatrixTranspose(&Buffer->View, &m_pD3D11_Camera->GetViewMatrix());
		D3DXMatrixTranspose(&Buffer->Projection, &m_pD3D11_Camera->GetProjectionMatrix());
	}
	GPU_Buffer->Unmap();
}

void D3D11_Interface::render()
{
	m_pGraphics->DrawBegin();

	// Rendering Pipeline
	{
		// Input Assembler
		m_pGraphics->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer->GetResource(), &m_pVertexBuffer->GetStride(), &m_pVertexBuffer->GetOffset());
		m_pGraphics->GetDeviceContext()->IASetIndexBuffer(m_pIndexBuffer->GetResource(), DXGI_FORMAT_R32_UINT, m_pIndexBuffer->GetOffset());
		m_pGraphics->GetDeviceContext()->IASetInputLayout(m_pInputLayout->GetResource());
		m_pGraphics->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		// Vertex Shader
		m_pGraphics->GetDeviceContext()->VSSetShader(static_cast<ID3D11VertexShader*>(m_pVertexShader->GetResource()), nullptr, NULL);
		m_pGraphics->GetDeviceContext()->VSSetConstantBuffers(0, 1, &GPU_Buffer->GetResource());

		// Rasterizer Stage
		m_pGraphics->GetDeviceContext()->RSSetState(m_pRasterizer->GetResource());

		// Pixel Shader
		m_pGraphics->GetDeviceContext()->PSSetShader(static_cast<ID3D11PixelShader*>(m_pPixelShader->GetResource()), nullptr, NULL);
		m_pGraphics->GetDeviceContext()->PSSetShaderResources(0, 1, &m_pTexture->GetResource());
		m_pGraphics->GetDeviceContext()->PSSetSamplers(0, 1, &m_pSamplerState->GetResource());

		// Output Merge
		m_pGraphics->GetDeviceContext()->OMSetBlendState(m_pBlendState->GetResource(), &m_pBlendState->GetBlendFactor(), m_pBlendState->GetSampleMask());

		// Draw Call
		m_pGraphics->GetDeviceContext()->DrawIndexed(6, 0, 0);
	}

	m_pGraphics->DrawEnd();
}
