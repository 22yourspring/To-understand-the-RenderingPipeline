#include "pch.h"
#include "Graphics.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
	SAFE_RELEASE(m_pRenderTargetView);
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDeviceContext);
	SAFE_RELEASE(m_pSwapChain);
}

void Graphics::DrawBegin()
{
	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);

	m_pDeviceContext->RSSetViewports(1, &Viewport.GetViewport());

	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, ClearColor);
}

void Graphics::DrawEnd()
{
	auto Hr = m_pSwapChain->Present(1, NULL);
	assert(SUCCEEDED(Hr));
}

void Graphics::Initialize()
{	
	DXGI_SWAP_CHAIN_DESC Desc;
	ZeroMemory(&Desc, sizeof(DXGI_SWAP_CHAIN_DESC));
	Desc.BufferDesc.Width = 0;
	Desc.BufferDesc.Height = 0;
	Desc.BufferDesc.RefreshRate.Numerator = 60;
	Desc.BufferDesc.RefreshRate.Denominator = 1;
	Desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	Desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	Desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	Desc.BufferCount = 1;
	Desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;
	Desc.OutputWindow = Settings::GetInst().GetWindowHwnd();
	Desc.Windowed = TRUE;
	Desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;	

	std::vector<D3D_FEATURE_LEVEL> Feature_Levels{ D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0 };

	auto Hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, NULL, Feature_Levels.data(), Feature_Levels.size(), D3D11_SDK_VERSION, &Desc, &m_pSwapChain, &m_pDevice, nullptr, &m_pDeviceContext);
	assert(SUCCEEDED(Hr));
}

void Graphics::CreateBuffer(const UINT& _Width, const UINT& _Height)
{
	// Back Buffer
	{
		auto Hr = m_pSwapChain->ResizeBuffers(NULL, _Width, _Height, DXGI_FORMAT_UNKNOWN, NULL);
		assert(SUCCEEDED(Hr));

		ID3D11Texture2D* BackBuffer = nullptr;
		Hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&BackBuffer));
		assert(SUCCEEDED(Hr));

		Hr = m_pDevice->CreateRenderTargetView(BackBuffer, nullptr, &m_pRenderTargetView);
		assert(SUCCEEDED(Hr));

		SAFE_RELEASE(BackBuffer);
	}

	// Viewport
	Viewport.SetValue(0.f, 0.f, static_cast<float>(_Width), static_cast<float>(_Height), 0.f, 1.f);
}
