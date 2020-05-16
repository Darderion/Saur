
#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Saur
{
	class SAUR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define SAUR_CORE_TRACE(...)	::Saur::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SAUR_CORE_INFO(...)		::Saur::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAUR_CORE_WARN(...)		::Saur::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAUR_CORE_ERROR(...)	::Saur::Log::GetCoreLogger()->error(__VA_ARGS__)

#define SAUR_TRACE(...)			::Saur::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SAUR_INFO(...)			::Saur::Log::GetClientLogger()->info(__VA_ARGS__)
#define SAUR_WARN(...)			::Saur::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SAUR_ERROR(...)			::Saur::Log::GetClientLogger()->error(__VA_ARGS__)
