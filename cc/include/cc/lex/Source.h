#pragma once

#include "cc/core/CC.h"

namespace cc
{
	class SourceFile 
	{
	public:
		const c8* path;
		std::string buffer;
		i32 size;
	public:
		SourceFile(const c8* path);
		std::string readFile();
	};
}
