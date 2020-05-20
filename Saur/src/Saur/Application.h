
#pragma once

#include "Core.h"
#include "IWindow.h"
#include "Events/ApplicationEvent.h"

namespace Saur
{
	class SAUR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<IWindow> m_Window;
		bool m_Running = true;
	};

	// Should be defined by client
	Application* CreateApplication();
}
