
#pragma once

#ifdef SAUR_PLATFORM_WINDOWS
	#ifdef SAUR_BUILD_DLL
		#define SAUR_API __declspec(dllexport)
	#else
		#define SAUR_API __declspec(dllimport)
	#endif
#else
	#error Saur only supports Windows
#endif

#ifdef SAUR_ASSERTION_ENABLED
	#define SAUR_ASSERT(x, ...) { if (!(x)) { SAUR_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SAUR_CORE_ASSERT(x, ...) { if (!(x)) { SAUR_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SAUR_ASSERT(x, ...)
	#define SAUR_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)
