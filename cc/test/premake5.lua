project "test"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/build/" .. outputdir .. "/bin")
	objdir ("%{wks.location}/build-int")

	files
	{
		"**.h",
		"**.cpp",
	}

	includedirs
	{
		"%{IncludeDir.LLVM}",
		"%{IncludeDir.LLVM_build}",
		"%{IncludeDir.cc}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.gtest}",
	}

	dependson 
	{ 
		"Gtest",
		"lib" 
	}


	links
	{
		"Gtest",
		"%{Library.cc}",

		"%{Library.LLVMAggressiveInstCombine}",
		"%{Library.LLVMAnalysis}",
		"%{Library.LLVMAsmParser}",
		"%{Library.LLVMAsmPrinter}",
		"%{Library.LLVMBinaryFormat}",
		"%{Library.LLVMBitReader}",
		"%{Library.LLVMBitstreamReader}",
		"%{Library.LLVMBitWriter}",
		"%{Library.LLVMCFGuard}",
		"%{Library.LLVMCFIVerify}",
		"%{Library.LLVMCodeGen}",
		"%{Library.LLVMCodeGenTypes}",
		"%{Library.LLVMCore}",
		"%{Library.LLVMCoroutines}",
		"%{Library.LLVMCoverage}",
		"%{Library.LLVMDebugInfoBTF}",
		"%{Library.LLVMDebugInfoCodeView}",
		"%{Library.LLVMDebuginfod}",
		"%{Library.LLVMDebugInfoDWARF}",
		"%{Library.LLVMDebugInfoGSYM}",
		"%{Library.LLVMDebugInfoLogicalView}",
		"%{Library.LLVMDebugInfoMSF}",
		"%{Library.LLVMDebugInfoPDB}",
		"%{Library.LLVMDemangle}",
		"%{Library.LLVMDiff}",
		"%{Library.LLVMDlltoolDriver}",
		"%{Library.LLVMDWARFLinker}",
		"%{Library.LLVMDWARFLinkerParallel}",
		"%{Library.LLVMDWP}",
		"%{Library.LLVMExecutionEngine}",
		"%{Library.LLVMExegesis}",
		"%{Library.LLVMExegesisX86}",
		"%{Library.LLVMExtensions}",
		"%{Library.LLVMFileCheck}",
		"%{Library.LLVMFrontendHLSL}",
		"%{Library.LLVMFrontendOpenACC}",
		"%{Library.LLVMFrontendOpenMP}",
		"%{Library.LLVMFuzzerCLI}",
		"%{Library.LLVMFuzzMutate}",
		"%{Library.LLVMGlobalISel}",
		"%{Library.LLVMInstCombine}",
		"%{Library.LLVMInstrumentation}",
		"%{Library.LLVMInterfaceStub}",
		"%{Library.LLVMInterpreter}",
		"%{Library.LLVMipo}",
		"%{Library.LLVMIRPrinter}",
		"%{Library.LLVMIRReader}",
		"%{Library.LLVMJITLink}",
		"%{Library.LLVMLibDriver}",
		"%{Library.LLVMLineEditor}",
		"%{Library.LLVMLinker}",
		"%{Library.LLVMLTO}",
		"%{Library.LLVMMC}",
		"%{Library.LLVMMCA}",
		"%{Library.LLVMMCDisassembler}",
		"%{Library.LLVMMCJIT}",
		"%{Library.LLVMMCParser}",
		"%{Library.LLVMMIRParser}",
		"%{Library.LLVMObjCARCOpts}",
		"%{Library.LLVMObjCopy}",
		"%{Library.LLVMObject}",
		"%{Library.LLVMObjectYAML}",
		"%{Library.LLVMOption}",
		"%{Library.LLVMOrcJIT}",
		"%{Library.LLVMOrcShared}",
		"%{Library.LLVMOrcTargetProcess}",
		"%{Library.LLVMPasses}",
		"%{Library.LLVMProfileData}",
		"%{Library.LLVMRemarks}",
		"%{Library.LLVMRuntimeDyld}",
		"%{Library.LLVMScalarOpts}",
		"%{Library.LLVMSelectionDAG}",
		"%{Library.LLVMSupport}",
		"%{Library.LLVMSymbolize}",
		"%{Library.LLVMTableGen}",
		"%{Library.LLVMTableGenCommon}",
		"%{Library.LLVMTableGenGlobalISel}",
		"%{Library.LLVMTarget}",
		"%{Library.LLVMTargetParser}",
		"%{Library.LLVMTextAPI}",
		"%{Library.LLVMTransformUtils}",
		"%{Library.LLVMVectorize}",
		"%{Library.LLVMWindowsDriver}",
		"%{Library.LLVMWindowsManifest}",
		"%{Library.LLVMX86AsmParser}",
		"%{Library.LLVMX86CodeGen}",
		"%{Library.LLVMX86Desc}",
		"%{Library.LLVMX86Disassembler}",
		"%{Library.LLVMX86Info}",
		"%{Library.LLVMX86TargetMCA}",
		"%{Library.LLVMXRay}",
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
