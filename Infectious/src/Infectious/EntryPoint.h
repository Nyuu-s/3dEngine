#pragma once


#ifdef INF_PLATFORM_WINDOWS

extern Infectious::Application* CreateApplication();

int main(int argc, char** argv) {
	printf("Infection spreading...");
	auto app = Infectious::CreateApplication();
	app->Run();
	delete app;

}

#endif
