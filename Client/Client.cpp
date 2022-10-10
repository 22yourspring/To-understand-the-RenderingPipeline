#include "pch.h"
#include "D3D11_Interface.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window::CreationWindow(hInstance, 500, 500);
	Window::VisibleWindow();

	Settings::GetInst().SetWindowHwnd(Window::g_WindowHandle);
	Settings::GetInst().SetWidth(static_cast<float>(Window::GetWindowWidth()));
	Settings::GetInst().SetHeight(static_cast<float>(Window::GetWindowHeight()));

	D3D11_Interface* pCore = new D3D11_Interface();

	while (Window::UpdateWindow())
	{
		pCore->update();
		pCore->render();
	}

	SAFE_DELETE(pCore);
	Window::DestroyWindow();

	return 0;
}