#pragma once

enum class ShaderScope : UINT
{
	Unknown	= 0U,
	VertexShader	= 1U << 0,
	PixelShader	= 1U << 1,

	Count
};

enum class Compilation_State : UINT 
{
	Unknown,
	Compiling,
	Succeeded,
	Failed,

	Count,
};

class D3D11_Shader final
{
public:
	D3D11_Shader(class Graphics* pGraphics);
	~D3D11_Shader();

private:
	ID3D11Device*		m_pDevice = nullptr;
	ID3DBlob*			m_pShaderBlob = nullptr;

	void*				m_pResource = nullptr;

public:
	std::string			m_Name = "";
	std::string			m_Path = "";

public:
	ShaderScope			m_ShaderState = ShaderScope::Unknown;
	Compilation_State	m_CompilationState = Compilation_State::Unknown;

public:
	auto GetResource() const { return m_pResource; }
	bool isValidResource() const { return m_pResource != nullptr; }

	auto GetShaderBlob() const { return m_pShaderBlob; }

	auto GetName() const { return m_Name; }
	void SetName(const std::string& _Name) { m_Name = _Name; }

	auto GetPath() const { return m_Path; }

public:
	auto GetShaderState() const { return m_ShaderState; }
	auto GetCompilationState() const { return m_CompilationState; }

	auto GetEntryPoint() const -> const char*;
	auto GetTargetProfile() const -> const char*;
	auto GetShaderModel() const -> const char*;

	bool isValidCompiled() const { return m_CompilationState == Compilation_State::Succeeded; }

public:
	void Create(const ShaderScope& _eState, const std::string& _ShaderPath);
	void Clear();

private:
	auto Compile(const ShaderScope& _eState, const std::string& _ShaderPath) -> void*;
};

