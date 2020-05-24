
#pragma once

#include "Core.h"
#include "IWindow.h"
#include "Saur/Layers/LayerStack.h"
#include "Saur/Events/Event.h"
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

		void PushLayer(ILayer* layer);
		void PushOverlay(ILayer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<IWindow> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	};

	// Should be defined by client
	Application* CreateApplication();
}
