#pragma once

#include "cc/Basic/CC.h"

namespace cc
{
	class SourceFile 
	{
	public:
		const c8* path;
		std::string buffer;
		i32 size;
		i32 id = 1; /// TODO
	public:
		SourceFile(const c8* path);
		std::string readFile();
	}; 
}
