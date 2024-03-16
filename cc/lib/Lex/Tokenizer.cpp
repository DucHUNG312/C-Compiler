#include "cc/Lex/Tokenizer.h"

namespace cc
{
	Tokenizer::Tokenizer(SourceFile& source)
		: source(std::move(source))
	{

	}

	Token* Tokenizer::tokenize()
	{
		Token* currentTok = &head;

		while (currentPos < source.size)
		{
			c8 c = current();
			switch (c)
			{
			case ' ':
			case '\t':
				next();
				break;
			case '\n':
				currentColumn = 1;
				currentLine++;
				currentPos++;
				break;
			case '\0':
				break;
			case '+':
				currentTok = currentTok->nextTok = makeToken(tok::plus, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
				next();
				break;
			case '-':
				currentTok = currentTok->nextTok = makeToken(tok::minus, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
				next();
				break;
			case '*':
				currentTok = currentTok->nextTok = makeToken(tok::star, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
				next();
				break;
			case '/':
				currentTok = currentTok->nextTok = makeToken(tok::slash, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
				next();
				break;
			case '=':
				if (matchNext('='))
				{
					currentTok = currentTok->nextTok = makeToken(tok::equal_equal, At(currentPos), At(currentPos + 2), currentLine, currentColumn);
					next(2);
				}
				else
				{
					currentTok = currentTok->nextTok = makeToken(tok::equal, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
					next();
				}
				break;
			default:
				if (isDigit(current()))
				{
					i32 pos = currentPos;

					while (isDigit(current()))
					{
						next();
					}

					currentTok = currentTok->nextTok = makeToken(tok::integer_literal, At(pos), At(currentPos), currentLine, currentColumn);
				}
				else
				{
					currentTok = currentTok->nextTok = makeToken(tok::unknown, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
					next();
				}
				break;
			}
		}

		currentTok = currentTok->nextTok = makeToken(tok::eof, At(currentPos), At(currentPos + 1), currentLine, currentColumn);
		return head.nextTok;
	}

	Token* Tokenizer::makeToken(tok::TokenKind kind, const c8* start, const c8* end, i32 line, i32 column)
	{
		return new Token(kind, start, end, line, column);
	}

	c8 Tokenizer::current()
	{
		return source.buffer[currentPos];
	}

	c8 Tokenizer::next(i32 offset)
	{
		currentPos += offset;
		currentColumn += offset;
		return current();
	}

	c8 Tokenizer::peek(i32 offset)
	{
		if (currentPos + offset >= source.size) return source.buffer[source.size];
		return source.buffer[currentPos + offset];
	}

	const c8* Tokenizer::At(i32 offset)
	{
		if (offset > source.size) return &source.buffer[source.size];
		return &source.buffer[offset];
	}

	void Tokenizer::whitespace()
	{
		while (isWhiteSpace(current()))
		{
			currentPos++;
			currentColumn++;
		}
	}

	Token Tokenizer::headToken()
	{
		return head;
	}

	bool Tokenizer::isAlpha(c8 c)
	{
		return (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			c == '_';
	}

	bool Tokenizer::isDigit(c8 c)
	{
		return c >= '0' && c <= '9';
	}

	bool Tokenizer::isAlphaNumeric(c8 c)
	{
		return isAlpha(c) || isDigit(c);
	}

	bool Tokenizer::isWhiteSpace(c8 c)
	{
		return c == ' ' ||  // space
			   c == '\t'; // tab
	}

	bool Tokenizer::match(c8 c)
	{
		return current() == c;
	}

	bool Tokenizer::matchNext(c8 c, i32 offset)
	{
		return peek(offset) == c;
	}
}
