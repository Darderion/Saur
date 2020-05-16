
#pragma once

#include "Core.h"

namespace Saur
{
	class SAUR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Should be defined by client
	Application* CreateApplication();
}
