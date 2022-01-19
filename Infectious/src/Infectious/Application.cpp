#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Infectious {
	


	
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1200, 500);
		INF_TRACE(e);
		while (true);
	}

}

