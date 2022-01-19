#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Infectious {

	class INFECTIOUS_API Log
	{
	public:

		static void Init();
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core log maccros
#define INF_CORE_TRACE(...)::Infectious::Log::getCoreLogger()->trace(__VA_ARGS__); 
#define INF_CORE_INFO(...) ::Infectious::Log::getCoreLogger()->info(__VA_ARGS__); 
#define INF_CORE_WARN(...) ::Infectious::Log::getCoreLogger()->warn(__VA_ARGS__); 
#define INF_CORE_ERROR(...)::Infectious::Log::getCoreLogger()->error(__VA_ARGS__); 
#define INF_CORE_FATAL(...)::Infectious::Log::getCoreLogger()->fatal(__VA_ARGS__); 


//client log macros 
#define INF_TRACE(...)::Infectious::Log::getClientLogger()->trace(__VA_ARGS__); 
#define INF_INFO(...):: Infectious::Log::getClientLogger()->info(__VA_ARGS__); 
#define INF_WARN(...):: Infectious::Log::getClientLogger()->warn(__VA_ARGS__); 
#define INF_ERROR(...)::Infectious::Log::getClientLogger()->error(__VA_ARGS__); 
#define INF_FATAL(...)::Infectious::Log::getClientLogger()->fatal(__VA_ARGS__); 
											
