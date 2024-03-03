#include <iostream>

#include "cc/core/CC.h"
#include "gtest/gtest.h"

using namespace cc;

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	debug::Logger::init();

	CC_LOG_DEBUG_NL(getCCVersion());

	return RUN_ALL_TESTS();
}
