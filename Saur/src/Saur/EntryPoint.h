
#pragma once

#ifdef SAUR_PLATFORM_WINDOWS

extern Saur::Application* Saur::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Saur::CreateApplication();
	app->Run();
	delete app;
}

#endif // SAUR_PLATFORM_WINDOWS
