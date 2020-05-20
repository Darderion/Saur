
#include "saurpch.h"

#include "Application.h"

#include "Log.h"

namespace Saur
{
#define BIND_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<IWindow>(IWindow::Create());
		m_Window->SetEventCallback(BIND_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);

		eventDispatcher.Dispatch<WindowCloseEvent>(BIND_FN(OnWindowClose));

		SAUR_CORE_TRACE(e);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		};
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
