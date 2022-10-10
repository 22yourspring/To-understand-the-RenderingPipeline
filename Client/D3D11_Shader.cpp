#include "pch.h"
#include "D3D11_Shader.h"

D3D11_Shader::D3D11_Shader(class Graphics* pGraphics)
{
	m_pDevice = pGraphics->GetDevice();
}

D3D11_Shader::~D3D11_Shader()
{
	Clear();
}

auto D3D11_Shader::GetEntryPoint() const -> const char*
{
	static const char* Entry_Point_VertexShader = "VS";
	static const char* Entry_Point_PixelShader	= "PS";

	switch (m_ShaderState)
	{
	case ShaderScope::VertexShader:	return Entry_Point_VertexShader;
	case ShaderScope::PixelShader:	return Entry_Point_PixelShader;
	}

	return nullptr;
}

auto D3D11_Shader::GetTargetProfile() const -> const char*
{
#if defined(_GRAPHICS_API_VERSION_D3D11)
	static const char* Target_Profile_VertexShader	= "vs_5_0";
	static const char* Target_Profile_PixelShader	= "ps_5_0";
#elif defined(_GRAPHICS_API_VERSION_D3D12)
	static const char* Target_Profile_VertexShader	= "vs_6_0";
	static const char* Target_Profile_PixelShader	= "ps_6_0";
#endif

	switch (m_ShaderState)
	{
	case ShaderScope::VertexShader:		return Target_Profile_VertexShader;
	case ShaderScope::PixelShader:		return Target_Profile_PixelShader;
	}

	return nullptr;
}

auto D3D11_Shader::GetShaderModel() const -> const char*
{
#if defined(_GRAPHICS_API_VERSION_D3D11)
	static const char* Shader_Model = "5_0";
#elif defined(_GRAPHICS_API_VERSION_D3D12)
	static const char* Shader_Model = "6_0";
#endif

	return Shader_Model;
}

void D3D11_Shader::Create(const ShaderScope& _eState, const std::string& _ShaderPath)
{
	m_ShaderState = _eState;
	m_CompilationState = Compilation_State::Compiling;

	m_pResource = Compile(_eState, _ShaderPath);
	m_CompilationState = isValidResource() ?  Compilation_State::Succeeded : Compilation_State::Failed;
}

void D3D11_Shader::Clear()
{
	switch (m_ShaderState)
	{
	case ShaderScope::VertexShader:
		{
			auto pShader = static_cast<ID3D11VertexShader*>(m_pResource);
			SAFE_RELEASE(pShader);
		}
		break;
	case ShaderScope::PixelShader:
		{
			auto pShader = static_cast<ID3D11PixelShader*>(m_pResource);
			SAFE_RELEASE(pShader);
		}
		break;
	}

	SAFE_RELEASE(m_pShaderBlob);

	m_Name.clear();
	m_Path.clear();

	m_ShaderState = ShaderScope::Unknown;
	m_CompilationState = Compilation_State::Unknown;
}

auto D3D11_Shader::Compile(const ShaderScope& _eState, const std::string& _ShaderPath) -> void*
{
	ID3DBlob*	Exception_Error = nullptr;

	HRESULT result = D3DX11CompileFromFileA(_ShaderPath.c_str(), nullptr, nullptr, GetEntryPoint(), GetTargetProfile(), NULL, NULL, nullptr, &m_pShaderBlob, &Exception_Error, nullptr);
	if (Exception_Error)
	{
		auto str = static_cast<const char*>(Exception_Error->GetBufferPointer());
		MessageBoxA(nullptr, str, "Shader Error !!!", MB_OK);
	}
	assert(SUCCEEDED(result));


	void* pShaderResource = nullptr;
	if (m_pShaderBlob)
	{
		switch (m_ShaderState)
		{
		case ShaderScope::VertexShader:
			result = m_pDevice->CreateVertexShader(m_pShaderBlob->GetBufferPointer(), m_pShaderBlob->GetBufferSize(), nullptr, reinterpret_cast<ID3D11VertexShader**>(&pShaderResource));
			assert(SUCCEEDED(result));
			break;
		case ShaderScope::PixelShader:
			result = m_pDevice->CreatePixelShader(m_pShaderBlob->GetBufferPointer(), m_pShaderBlob->GetBufferSize(), nullptr, reinterpret_cast<ID3D11PixelShader**>(&pShaderResource));
			assert(SUCCEEDED(result));
			break;
		}
	}

	return pShaderResource;
}