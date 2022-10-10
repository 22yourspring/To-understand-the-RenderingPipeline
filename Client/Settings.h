#pragma once

class Settings final
{
private:
	Settings() = default;
	~Settings() = default;

private:
	HWND	WindowHandle = nullptr;
	float	Width = 0.f;
	float	Height = 0.f;

public:
	static Settings& GetInst()
	{
		static Settings Instance;
		return Instance;
	}

public:
	auto GetWindowHwnd() const -> HWND { return WindowHandle; }
	void SetWindowHwnd(HWND _Handle) { this->WindowHandle = _Handle; }

	auto GetWidth() const -> const float& { return Width; }
	void SetWidth(const float& _Width) { this->Width = _Width; }

	auto GetHeight() const -> const float& { return Height; }
	void SetHeight(const float& _Height) { this->Height = _Height; }
};