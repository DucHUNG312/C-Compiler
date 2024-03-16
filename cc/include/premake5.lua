project "include"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/build/" .. outputdir .. "/lib")
	objdir ("%{wks.location}/build-int")

	files
	{
		"**.h",
		"**.hpp",
		"**.inc",
		"**.inc.in",
		"**.def",
	}

	includedirs
	{
		"%{IncludeDir.LLVM}",
		"%{IncludeDir.LLVM_build}",
		"%{IncludeDir.cc}",
		"%{IncludeDir.spdlog}",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"
		defines "CC_PLATFORM_WINDOWS"

	filter "configurations:Debug"
		defines "CC_DEBUG_BUILD"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines 
		{
			"CC_DEBUG_BUILD2",
			--"CC_RELEASE_BUILD"
		}
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CC_DIST_BUILD"
		runtime "Release"
		optimize "on"
