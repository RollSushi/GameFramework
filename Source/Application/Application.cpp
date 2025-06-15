#include "Application.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::Instance().Excute();
	return 0;
}

void Application::Excute() {
	if (!m_window.Create(1280, 720, L"Base_Framework", L"Window")) {
		assert(false && "ウィンドウ作成失敗");
		return;
	}

	while (true) {
		if (!m_window.ProcessMessage()) {
			break;
		}
	}
}