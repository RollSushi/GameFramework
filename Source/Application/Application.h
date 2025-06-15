#pragma once

#include "../System/Window.h"

class Application
{
public:
	void Excute();

private:
	Window m_window;

	Application() {}

public:
	static Application& Instance()
	{
		static Application instance;
		return instance;
	}
};