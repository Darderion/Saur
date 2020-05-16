
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
