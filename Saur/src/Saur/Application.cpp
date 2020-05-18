
#include "saurpch.h"

#include "Application.h"

#include "Log.h"
#include "Events/Application.h"

namespace Saur
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(2, 2);
		SAUR_TRACE(e);

		while (1) {};
	}
}
