
#include "saurpch.h"

#include "Application.h"

#include "Log.h"
#include "Events/Application.h"

namespace Saur
{
	Application::Application()
	{
		m_Window = std::unique_ptr<IWindow>(IWindow::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		int i = 0;
		while (m_Running)
		{
			i = (i + 1) % 1000000;
			SAUR_INFO(i);
			m_Window->OnUpdate();
		};
	}
}
