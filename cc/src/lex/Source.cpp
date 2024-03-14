#include "cc/lex/Source.h"

namespace cc
{
	SourceFile::SourceFile(const c8* path)
		: path(path)
	{
		buffer = readFile();
		size = buffer.size();
	}

	std::string SourceFile::readFile()
	{
		std::ifstream fileStream(path); // Open the file in binary mode

		if (!fileStream.is_open())
		{
#ifdef CC_DEBUG_BUILD
			CC_LOG_CRITICAL_NL("Error opening file {}, in {} at {}", path, __FILE__, __LINE__);
			CC_BREAK();
#endif // CC_DEBUG_BUILD
		}

		std::ostringstream sstr;
		sstr << fileStream.rdbuf();
		return sstr.str();
	};
}
