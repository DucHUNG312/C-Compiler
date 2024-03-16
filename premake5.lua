include "Scripts/PremakeUtils/PremakeCommon.lua"
include "Scripts/PremakeUtils/PremakeDefines.lua"
include "Scripts/PremakeUtils/PremakeDependencies.lua"

workspace "CC"
	architecture "x86_64"
	startproject "test"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}
	
	filter "language:C++ or language:C"
		architecture "x86_64"
	filter ""

	group "ThirdParty"
		include "thirdparty/googletest"
	group ""

	group "CC"
		include "cc/include"
		include "cc/lib"
		include "cc/test"
	group ""
	

	
