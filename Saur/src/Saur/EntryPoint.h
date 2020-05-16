
#pragma once

#ifdef SAUR_PLATFORM_WINDOWS

extern Saur::Application* Saur::CreateApplication();

int main(int argc, char** argv)
{
	Saur::Log::Init();

	SAUR_CORE_INFO("Initializing application");
	auto app = Saur::CreateApplication();
	SAUR_CORE_INFO("Running application");
	app->Run();
	SAUR_CORE_INFO("Deleting application");
	delete app;
}

#endif // SAUR_PLATFORM_WINDOWS
