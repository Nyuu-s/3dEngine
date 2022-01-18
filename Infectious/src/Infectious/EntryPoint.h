#pragma once


#ifdef INF_PLATFORM_WINDOWS

extern Infectious::Application* CreateApplication();

int main(int argc, char** argv) {

	Infectious::Log::Init();
	INF_CORE_TRACE("INITIALIZED LOGGING SYSTEME");
	INF_ERROR("welcome");

	auto app = Infectious::CreateApplication();
	app->Run();
	delete app;

}

#endif
