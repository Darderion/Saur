
#pragma once

#include "Core.h"
#include "IWindow.h"

namespace Saur
{
	class SAUR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<IWindow> m_Window;
		bool m_Running = true;
	};

	// Should be defined by client
	Application* CreateApplication();
}
