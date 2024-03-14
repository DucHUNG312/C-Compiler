#pragma once

#include "cc/lex/Token.h"
#include "cc/lex/Source.h"

namespace cc
{
	class Tokenizer
	{
	public:
		Tokenizer(SourceFile& source);
		Token* tokenize();
		Token* makeToken(tok::TokenKind kind, const c8* start, const c8* end, i32 line);
		c8 current();
		c8 next(i32 offset = 1);
		c8 peek(i32 offset = 1);
		const c8* At(i32 offset);
		void whitespace();
		Token headToken();

		bool isAlpha(c8 c);
		bool isDigit(c8 c);
		bool isAlphaNumeric(c8 c);
		bool isWhiteSpace(c8 c);
		bool match(c8 c);
		bool matchNext(c8 c, i32 offset = 1);
	private:
		SourceFile source;
		i32 currentPos = 0;
		i32 currentLine = 1;
		i32 column = 1;
		Token head = {};
	};
}
