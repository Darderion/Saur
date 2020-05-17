workspace "Saur"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Saur"
	location "Saur"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SAUR_PLATFORM_WINDOWS",
			"SAUR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "SAUR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SAUR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SAUR_Dist"
		optimize "On"



project "SandBox"
	location "SandBox"
	kind "ConsoleApp"

	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Saur/vendor/spdlog/include",
		"Saur/src"
	}

	links
	{
		"Saur"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SAUR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SAUR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SAUR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SAUR_Dist"
		optimize "On"










