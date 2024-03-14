#include "cc/lex/Token.h"

namespace cc
{
	namespace tok
	{
		static const c8* const tokNames[] = {
#define TOK(ID) #ID,
#define KEYWORD(ID, FLAG) #ID,
#include "cc/lex/TokenKinds.def"
			nullptr
		};

		const c8* GetTokenName(TokenKind Kind)
		{
			if (Kind < NUMS_TOKENS)
				return tokNames[Kind];

			CC_UNREACHABLE("unknown TokenKind");
			return tokNames[0]; // unknown
		}

		const c8* GetPunctuatorSpelling(TokenKind Kind)
		{
			switch (Kind)
			{
#define PUNCTUATOR(ID, SP) case ID: return SP;
#include "cc/lex/TokenKinds.def"
			default: break;
			}
			return nullptr;
		}

		const c8* GetKeywordSpelling(TokenKind Kind)
		{
			switch (Kind)
			{
#define KEYWORD(ID, FLAG) case kw_##ID: return #ID;
#include "cc/lex/TokenKinds.def"
			default: break;
			}
		return nullptr;
		}
	}

	Token::Token(tok::TokenKind kind, const c8* start, const c8* end, i32 line)
		: kind(kind), start(start), end(end), line(line)
	{
		length = end - start;
		rawVal = std::string(start, length);
		if (isLiteralToken(kind))
		{
			literal = true;
			setLiteralVal(kind, rawVal);
		}
	}

	void Token::setLiteralVal(tok::TokenKind kind, std::string& rawVal)
	{
		if (kind == tok::integer_literal)
		{
			literalVal = std::stoi(rawVal); /// TODO
		}
		else if (kind == tok::string_literal)
		{
			literalVal = rawVal;
		}
		else
		{
#ifdef CC_DEBUG_BUILD
			CC_LOG_CRITICAL_NL("Literal token only! in {} at {}", __FILE__, __LINE__);
			CC_BREAK();
#endif // CC_DEBUG_BUILD
		}
	}
}
