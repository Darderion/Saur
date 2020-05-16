
#pragma once

namespace Saur
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Should be defined by client
	Application* CreateApplication();
}
