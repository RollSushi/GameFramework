#include "Application.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::Instance().Excute();
	return 0;
}

void Application::Excute() {
	if (!m_window.Create(1280, 720, L"Base_Framework", L"Window")) {
		assert(false && "�E�B���h�E�쐬���s");
		return;
	}

	while (true) {
		if (!m_window.ProcessMessage()) {
			break;
		}
	}
}