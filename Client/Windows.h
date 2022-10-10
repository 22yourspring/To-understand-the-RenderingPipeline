#pragma once

namespace Window
{
	static HINSTANCE	g_InstanceHandle;
	static HWND			g_WindowHandle;

	// Window Proc
	inline LRESULT CALLBACK WndProc(HWND _Handle, UINT _message, WPARAM _wParam, LPARAM _lParam)
	{
		switch (_message)
		{
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(NULL);
			break;
		default:
			return DefWindowProc(_Handle, _message, _wParam, _lParam);
		}

		return NULL;
	}

	// Creation Window
	inline void CreationWindow(HINSTANCE _InstanceHandle, const UINT& _Width, const UINT& _Height)
	{
		WNDCLASSEX		WindowClass;

		WindowClass.cbClsExtra = NULL;
		WindowClass.cbWndExtra = NULL;
		WindowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
		WindowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		WindowClass.hIcon = LoadIcon(nullptr, IDI_ERROR);
		WindowClass.hIconSm = LoadIcon(nullptr, IDI_ERROR);
		WindowClass.hInstance = _InstanceHandle;
		WindowClass.lpfnWndProc = WndProc;
		WindowClass.lpszClassName = L"D2D11GameProject";
		WindowClass.lpszMenuName = nullptr;
		WindowClass.style = CS_HREDRAW | CS_VREDRAW;
		WindowClass.cbSize = sizeof(WNDCLASSEX);

		auto Hr = RegisterClassEx(&WindowClass);
		assert(Hr);

		g_WindowHandle = CreateWindowExW(WS_EX_APPWINDOW, WindowClass.lpszClassName, WindowClass.lpszClassName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, static_cast<int>(_Width), static_cast<int>(_Height), nullptr, nullptr, _InstanceHandle, nullptr);
		assert(g_WindowHandle);
	}

	// Visible Window
	inline void VisibleWindow()
	{
		SetForegroundWindow(g_WindowHandle);
		SetFocus(g_WindowHandle);
		ShowCursor(TRUE);
		ShowWindow(g_WindowHandle, SW_NORMAL);
		UpdateWindow(g_WindowHandle);
	}

	// Update Window
	inline const bool UpdateWindow()
	{
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));

		if (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		return msg.message != WM_QUIT;
	}

	// Destroy Window
	inline void DestroyWindow()
	{
		DestroyWindow(g_WindowHandle);
		UnregisterClass(L"D2D11GameProject", g_InstanceHandle);
	}

	// Resolution Width Window
	inline const UINT GetWindowWidth()
	{
		RECT rt;
		GetClientRect(g_WindowHandle, &rt);
		return static_cast<UINT>(rt.right - rt.left);
	}

	// Resolution Height Window
	inline const UINT GetWindowHeight()
	{
		RECT rt;
		GetClientRect(g_WindowHandle, &rt);
		return static_cast<UINT>(rt.bottom - rt.top);
	}
}