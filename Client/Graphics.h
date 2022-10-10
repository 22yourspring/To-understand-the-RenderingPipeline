#pragma once
class Graphics final
{
public:
	Graphics();
	~Graphics();

private:
	ID3D11Device*				m_pDevice = nullptr;
	ID3D11DeviceContext*		m_pDeviceContext = nullptr;
	IDXGISwapChain*				m_pSwapChain = nullptr;
	ID3D11RenderTargetView*		m_pRenderTargetView = nullptr;
	D3D11_Viewport				Viewport = D3D11_Viewport::Undefined_Viewport;
	D3DXCOLOR					ClearColor = 0xffffffff;

public:
	auto GetDevice() -> ID3D11Device* { return m_pDevice; }
	auto GetDeviceContext() ->ID3D11DeviceContext* { return m_pDeviceContext; }

public:
	void DrawBegin();
	void DrawEnd();

public:
	void Initialize();
	void CreateBuffer(const UINT& _Width, const UINT& _Height);
};

