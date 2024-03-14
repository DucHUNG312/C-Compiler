#include "cc/core/CC.h"

#include "cc/lex/Source.h"
#include "cc/lex/Tokenizer.h"

using namespace cc;

i32 main(i32 argc, c8** argv)
{
	debug::Logger::init();

	const c8* filePath = "D:\\dev\\Compiler\\cc\\test\\testdata\\testdata.lcc";

	SourceFile source(filePath);

	Tokenizer tokenizer(source);

	tokenizer.tokenize();

	Token* current = tokenizer.headToken().nextTok;

	while (current->getKind() != tok::eof)
	{
		if (current->getKind() == tok::integer_literal)
		{
			CC_LOG_DEBUG("{} ", current->literalVal.getValue<i32>());
		}
		else
		{
			CC_LOG_DEBUG("{} ", current->rawVal);
		}
		current = current->nextTok;
	}
}
