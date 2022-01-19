workspace "Infectious"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Infectious"
	location "Infectious"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Infectious/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"INF_PLATFORM_WINDOWS",
			"INF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "INF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "INF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "INF_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Infectious/vendor/spdlog/include",
		"Infectious/src"
	}

	links
	{
		"Infectious"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"INF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "INF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "INF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "INF_DIST"
		optimize "On" 