#include"Window.h"


LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
		break;
	}
	return 0;
}

bool Window::Create(int width, int height, const std::wstring& titleName, const std::wstring& windowClassName) {
	HINSTANCE hInset = GetModuleHandle(0);

	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc=(WNDPROC)WindowProcedure;
	wc.lpszClassName= windowClassName.c_str();
	wc.hInstance = hInset;

	if (!RegisterClassEx(&wc)) {
		return false;
	}

	m_hWnd = CreateWindow(
		windowClassName.c_str(),
		titleName.c_str(),
		WS_OVERLAPPEDWINDOW-WS_THICKFRAME,
		0, 
		0,
		width,
		height,
		nullptr,
		nullptr,
		hInset,
		this
	);

	if (m_hWnd==nullptr) {
		return false;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	UpdateWindow(m_hWnd);

	return true;
}


bool Window::ProcessMessage() {
	MSG msg;
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			return false;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}
