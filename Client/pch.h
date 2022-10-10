#pragma once

#define NOMINMAX

#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// Window
#include <Windows.h>
#include <assert.h>

// STL
#include <iostream>
#include <vector>

// Define
#include "define.h"

// DirectX
#include <d3dcompiler.h>
#include <d3d11.h>
#include <D3DX10math.h>
#include <D3DX11async.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "d3dcompiler.lib")

// Utility
#include "Geometry_Generator.h"

// Framework
#include "D3D11_Vertex.h"
#include "D3D11_Geometry.h"
#include "D3D11_VertexBuffer.h"
#include "D3D11_IndexBuffer.h"
#include "D3D11_InputLayout.h"
#include "D3D11_Shader.h"
#include "D3D11_ConstantBuffer.h"
#include "D3D11_RasterizerState.h"
#include "D3D11_Viewport.h"
#include "D3D11_Texture.h"
#include "D3D11_SamplerState.h"
#include "D3D11_BlendState.h"

#include "Settings.h"
#include "Graphics.h"