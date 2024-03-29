LLVM = os.getenv("LLVM17")

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["LLVM"] = "%{LLVM}/llvm/include"
IncludeDir["LLVM_build"] = "%{LLVM}/build/include"
IncludeDir["cc"] = "%{wks.location}/cc/include"
IncludeDir["spdlog"] = "%{wks.location}/thirdparty/spdlog/include"
IncludeDir["gtest"] = "%{wks.location}/thirdparty/googletest/googletest/include"
IncludeDir["gtest_folder"] = "%{wks.location}/thirdparty/googletest/googletest"

LibraryDir = {}
LibraryDir["cc"] = "%{wks.location}/build/" .. outputdir .. "/lib"
LibraryDir["LLVM"] = "%{LLVM}/build/Release/lib"
LibraryDir["LLVM17_lib"] = "%{wks.location}/build/" .. outputdir .. "/lib"

Library = {}
Library["cc"] = "%{LibraryDir.cc}/lib.lib"
Library["LLVMAggressiveInstCombine"] = "%{LibraryDir.LLVM}/LLVMAggressiveInstCombine.lib"
Library["LLVMAnalysis"] = "%{LibraryDir.LLVM}/LLVMAnalysis.lib"
Library["LLVMAsmParser"] = "%{LibraryDir.LLVM}/LLVMAsmParser.lib"
Library["LLVMAsmPrinter"] = "%{LibraryDir.LLVM}/LLVMAsmPrinter.lib"
Library["LLVMBinaryFormat"] = "%{LibraryDir.LLVM}/LLVMBinaryFormat.lib"
Library["LLVMBitReader"] = "%{LibraryDir.LLVM}/LLVMBitReader.lib"
Library["LLVMBitstreamReader"] = "%{LibraryDir.LLVM}/LLVMBitstreamReader.lib"
Library["LLVMBitWriter"] = "%{LibraryDir.LLVM}/LLVMBitWriter.lib"
Library["LLVMCFGuard"] = "%{LibraryDir.LLVM}/LLVMCFGuard.lib"
Library["LLVMCFIVerify"] = "%{LibraryDir.LLVM}/LLVMCFIVerify.lib"
Library["LLVMCodeGen"] = "%{LibraryDir.LLVM}/LLVMCodeGen.lib"
Library["LLVMCodeGenTypes"] = "%{LibraryDir.LLVM}/LLVMCodeGenTypes.lib"
Library["LLVMCore"] = "%{LibraryDir.LLVM}/LLVMCore.lib"
Library["LLVMCoroutines"] = "%{LibraryDir.LLVM}/LLVMCoroutines.lib"
Library["LLVMCoverage"] = "%{LibraryDir.LLVM}/LLVMCoverage.lib"
Library["LLVMDebugInfoBTF"] = "%{LibraryDir.LLVM}/LLVMDebugInfoBTF.lib"
Library["LLVMDebugInfoCodeView"] = "%{LibraryDir.LLVM}/LLVMDebugInfoCodeView.lib"
Library["LLVMDebuginfod"] = "%{LibraryDir.LLVM}/LLVMDebuginfod.lib"
Library["LLVMDebugInfoDWARF"] = "%{LibraryDir.LLVM}/LLVMDebugInfoDWARF.lib"
Library["LLVMDebugInfoGSYM"] = "%{LibraryDir.LLVM}/LLVMDebugInfoGSYM.lib"
Library["LLVMDebugInfoLogicalView"] = "%{LibraryDir.LLVM}/LLVMDebugInfoLogicalView.lib"
Library["LLVMDebugInfoMSF"] = "%{LibraryDir.LLVM}/LLVMDebugInfoMSF.lib"
Library["LLVMDebugInfoPDB"] = "%{LibraryDir.LLVM}/LLVMDebugInfoPDB.lib"
Library["LLVMDemangle"] = "%{LibraryDir.LLVM}/LLVMDemangle.lib"
Library["LLVMDiff"] = "%{LibraryDir.LLVM}/LLVMDiff.lib"
Library["LLVMDlltoolDriver"] = "%{LibraryDir.LLVM}/LLVMDlltoolDriver.lib"
Library["LLVMDWARFLinker"] = "%{LibraryDir.LLVM}/LLVMDWARFLinker.lib"
Library["LLVMDWARFLinkerParallel"] = "%{LibraryDir.LLVM}/LLVMDWARFLinkerParallel.lib"
Library["LLVMDWP"] = "%{LibraryDir.LLVM}/LLVMDWP.lib"
Library["LLVMExecutionEngine"] = "%{LibraryDir.LLVM}/LLVMExecutionEngine.lib"
Library["LLVMExegesis"] = "%{LibraryDir.LLVM}/LLVMExegesis.lib"
Library["LLVMExegesisX86"] = "%{LibraryDir.LLVM}/LLVMExegesisX86.lib"
Library["LLVMExtensions"] = "%{LibraryDir.LLVM}/LLVMExtensions.lib"
Library["LLVMFileCheck"] = "%{LibraryDir.LLVM}/LLVMFileCheck.lib"
Library["LLVMFrontendHLSL"] = "%{LibraryDir.LLVM}/LLVMFrontendHLSL.lib"
Library["LLVMFrontendOpenACC"] = "%{LibraryDir.LLVM}/LLVMFrontendOpenACC.lib"
Library["LLVMFrontendOpenMP"] = "%{LibraryDir.LLVM}/LLVMFrontendOpenMP.lib"
Library["LLVMFuzzerCLI"] = "%{LibraryDir.LLVM}/LLVMFuzzerCLI.lib"
Library["LLVMFuzzMutate"] = "%{LibraryDir.LLVM}/LLVMFuzzMutate.lib"
Library["LLVMGlobalISel"] = "%{LibraryDir.LLVM}/LLVMGlobalISel.lib"
Library["LLVMInstCombine"] = "%{LibraryDir.LLVM}/LLVMInstCombine.lib"
Library["LLVMInstrumentation"] = "%{LibraryDir.LLVM}/LLVMInstrumentation.lib"
Library["LLVMInterfaceStub"] = "%{LibraryDir.LLVM}/LLVMInterfaceStub.lib"
Library["LLVMInterpreter"] = "%{LibraryDir.LLVM}/LLVMInterpreter.lib"
Library["LLVMipo"] = "%{LibraryDir.LLVM}/LLVMipo.lib"
Library["LLVMIRPrinter"] = "%{LibraryDir.LLVM}/LLVMIRPrinter.lib"
Library["LLVMIRReader"] = "%{LibraryDir.LLVM}/LLVMIRReader.lib"
Library["LLVMJITLink"] = "%{LibraryDir.LLVM}/LLVMJITLink.lib"
Library["LLVMLibDriver"] = "%{LibraryDir.LLVM}/LLVMLibDriver.lib"
Library["LLVMLineEditor"] = "%{LibraryDir.LLVM}/LLVMLineEditor.lib"
Library["LLVMLinker"] = "%{LibraryDir.LLVM}/LLVMLinker.lib"
Library["LLVMLTO"] = "%{LibraryDir.LLVM}/LLVMLTO.lib"
Library["LLVMMC"] = "%{LibraryDir.LLVM}/LLVMMC.lib"
Library["LLVMMCA"] = "%{LibraryDir.LLVM}/LLVMMCA.lib"
Library["LLVMMCDisassembler"] = "%{LibraryDir.LLVM}/LLVMMCDisassembler.lib"
Library["LLVMMCJIT"] = "%{LibraryDir.LLVM}/LLVMMCJIT.lib"
Library["LLVMMCParser"] = "%{LibraryDir.LLVM}/LLVMMCParser.lib"
Library["LLVMMIRParser"] = "%{LibraryDir.LLVM}/LLVMMIRParser.lib"
Library["LLVMObjCARCOpts"] = "%{LibraryDir.LLVM}/LLVMObjCARCOpts.lib"
Library["LLVMObjCopy"] = "%{LibraryDir.LLVM}/LLVMObjCopy.lib"
Library["LLVMObject"] = "%{LibraryDir.LLVM}/LLVMObject.lib"
Library["LLVMObjectYAML"] = "%{LibraryDir.LLVM}/LLVMObjectYAML.lib"
Library["LLVMOption"] = "%{LibraryDir.LLVM}/LLVMOption.lib"
Library["LLVMOrcJIT"] = "%{LibraryDir.LLVM}/LLVMOrcJIT.lib"
Library["LLVMOrcShared"] = "%{LibraryDir.LLVM}/LLVMOrcShared.lib"
Library["LLVMOrcTargetProcess"] = "%{LibraryDir.LLVM}/LLVMOrcTargetProcess.lib"
Library["LLVMPasses"] = "%{LibraryDir.LLVM}/LLVMPasses.lib"
Library["LLVMProfileData"] = "%{LibraryDir.LLVM}/LLVMProfileData.lib"
Library["LLVMRemarks"] = "%{LibraryDir.LLVM}/LLVMRemarks.lib"
Library["LLVMRuntimeDyld"] = "%{LibraryDir.LLVM}/LLVMRuntimeDyld.lib"
Library["LLVMScalarOpts"] = "%{LibraryDir.LLVM}/LLVMScalarOpts.lib"
Library["LLVMSelectionDAG"] = "%{LibraryDir.LLVM}/LLVMSelectionDAG.lib"
Library["LLVMSupport"] = "%{LibraryDir.LLVM}/LLVMSupport.lib"
Library["LLVMSymbolize"] = "%{LibraryDir.LLVM}/LLVMSymbolize.lib"
Library["LLVMTableGen"] = "%{LibraryDir.LLVM}/LLVMTableGen.lib"
Library["LLVMTableGenCommon"] = "%{LibraryDir.LLVM}/LLVMTableGenCommon.lib"
Library["LLVMTableGenGlobalISel"] = "%{LibraryDir.LLVM}/LLVMTableGenGlobalISel.lib"
Library["LLVMTarget"] = "%{LibraryDir.LLVM}/LLVMTarget.lib"
Library["LLVMTargetParser"] = "%{LibraryDir.LLVM}/LLVMTargetParser.lib"
Library["LLVMTextAPI"] = "%{LibraryDir.LLVM}/LLVMTextAPI.lib"
Library["LLVMTransformUtils"] = "%{LibraryDir.LLVM}/LLVMTransformUtils.lib"
Library["LLVMVectorize"] = "%{LibraryDir.LLVM}/LLVMVectorize.lib"
Library["LLVMWindowsDriver"] = "%{LibraryDir.LLVM}/LLVMWindowsDriver.lib"
Library["LLVMWindowsManifest"] = "%{LibraryDir.LLVM}/LLVMWindowsManifest.lib"
Library["LLVMX86AsmParser"] = "%{LibraryDir.LLVM}/LLVMX86AsmParser.lib"
Library["LLVMX86CodeGen"] = "%{LibraryDir.LLVM}/LLVMX86CodeGen.lib"
Library["LLVMX86Desc"] = "%{LibraryDir.LLVM}/LLVMX86Desc.lib"
Library["LLVMX86Disassembler"] = "%{LibraryDir.LLVM}/LLVMX86Disassembler.lib"
Library["LLVMX86Info"] = "%{LibraryDir.LLVM}/LLVMX86Info.lib"
Library["LLVMX86TargetMCA"] = "%{LibraryDir.LLVM}/LLVMX86TargetMCA.lib"
Library["LLVMXRay"] = "%{LibraryDir.LLVM}/LLVMXRay.lib"
Library["LTO"] = "%{LibraryDir.LLVM}/LTO.lib"

