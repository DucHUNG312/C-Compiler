-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["cc"] = "%{wks.location}/cc/include"
IncludeDir["spdlog"] = "%{wks.location}/thirdparty/spdlog/include"
IncludeDir["gtest"] = "%{wks.location}/thirdparty/googletest/googletest/include"
IncludeDir["gtest_folder"] = "%{wks.location}/thirdparty/googletest/googletest"

LibraryDir = {}
LibraryDir["cc"] = "%{wks.location}/build/" .. outputdir .. "/lib"

Library = {}
Library["cc"] = "%{LibraryDir.cc}/cc.lib"