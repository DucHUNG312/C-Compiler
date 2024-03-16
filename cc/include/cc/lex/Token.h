#pragma once

#include "cc/Basic/PCH.h"
#include "cc/Basic/CC.h"
#include "cc/Basic/Object.h"

namespace cc
{
	namespace tok
	{
		enum TokenKind : unsigned short
		{
#define TOK(ID) ID,
#include "cc/lex/TokenKinds.def"
			NUMS_TOKENS
		};

		const c8* GetTokenName(TokenKind Kind);
		const c8* GetPunctuatorSpelling(TokenKind Kind);
		const c8* GetKeywordSpelling(TokenKind Kind);
	}
	
	class Token
	{
	public:
		Token() = default;
		Token(tok::TokenKind kind, const c8* start, const c8* end, i32 line, i32 column);

		bool isEOF()
		{
			return kind == tok::eof;
		}

		bool isEOL()
		{
			return kind == tok::eol;
		}

		bool isLiteral()
		{
			return literal;
		}

		static bool isLiteralToken(tok::TokenKind tokKind)
		{
			return tokKind == tok::integer_literal || tokKind == tok::string_literal;
		}

		tok::TokenKind getKind() { return kind; }
		i32 getLine() { return line; }
		i32 getLength() { return length; }
		const c8* getStartChar() { return start; }
		const c8* getEndChar() { return end; }
		std::string getRawValue() { return rawVal; }
		const c8* getKindName();
	private:
		static Object setLiteralObject(std::string& rawVal, tok::TokenKind kind);
	public:
		Token* nextTok;
		bool literal = false;
		Object literalVal;
		tok::TokenKind kind = tok::empty;
		std::string rawVal;
		i32 line;
		i32 length;
		i32 column;
		const c8* start;
		const c8* end;
	};
}
