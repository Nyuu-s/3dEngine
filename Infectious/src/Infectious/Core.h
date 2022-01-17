#pragma once

#ifdef INF_PLATFORM_WINDOWS
	#ifdef INF_BUILD_DLL
		#define INFECTIOUS_API __declspec(dllexport)
	#else
		#define INFECTIOUS_API __declspec(dllimport)
	#endif // INF_BUILD_DLL
#else
	#error Infectious only support windows

#endif // INF_PLATFORM_WINDOWS
