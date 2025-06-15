#pragma once

#include <Windows.h>
#include <string>

class Window
{
public:
/// <summary>
/// ƒEƒBƒ“ƒhì¬
/// </summary>

	bool Create(int width, int height, const std::wstring& titleNamw,const std::wstring& windowClassName);
	bool ProcessMessage();
private:
	HWND m_hWnd;
};