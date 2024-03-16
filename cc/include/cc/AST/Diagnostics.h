#pragma once

#include "cc/Basic/CC.h"
#include "cc/Lex/Token.h"
#include "cc/Lex/Source.h"

namespace cc
{
	struct DiagnosticInfo
	{
		enum DiagnosticLevel
		{
			Ignored,
			Note,
			Remark,
			Warning,
			Error,
			Fatal
		};

		enum DiagnosticTypes
		{
			SyntaxError
		};

		DiagnosticLevel level;
		DiagnosticTypes type;
		SourceFile source;
		Token token;

		std::string LevelToString()
		{
			std::string ret;
			switch (level)
			{
			case cc::DiagnosticInfo::Ignored:
				ret = "Ignored";
				break;
			case cc::DiagnosticInfo::Note:
				ret = "Note";
				break;
			case cc::DiagnosticInfo::Remark:
				ret = "Remark";
				break;
			case cc::DiagnosticInfo::Warning:
				ret = "Warning";
				break;
			case cc::DiagnosticInfo::Error:
				ret = "Error";
				break;
			case cc::DiagnosticInfo::Fatal:
				ret = "Fatal";
				break;
			default:
				ret = "Unknown";
				break;
			}

			return ret;
		}

		std::string TypeToString()
		{
			std::string ret;
			switch (type)
			{
			case cc::DiagnosticInfo::SyntaxError:
				ret = "Syntax error";
				break;
			default:
				ret = "Unknown";
				break;
			}

			return ret;
		}
	};

	class DiagnosticConsumer;

	class DiagnosticsEngine
	{
	public:
		DiagnosticsEngine(DiagnosticConsumer* client = nullptr, bool shouldOwnClient = true)
			: client(client), shouldOwnClient(shouldOwnClient)
		{

		}

		enum Level 
		{
			Ignored = DiagnosticInfo::Ignored,
			Note = DiagnosticInfo::Note,
			Remark = DiagnosticInfo::Remark,
			Warning = DiagnosticInfo::Warning,
			Error = DiagnosticInfo::Error,
			Fatal = DiagnosticInfo::Fatal
		};

		DiagnosticConsumer* getClient() { return client; }
		const DiagnosticConsumer* getClient() const { return client; }

		CC_NONCOPYABLEANDMOVE(DiagnosticsEngine);
	private:
		DiagnosticConsumer* client;
		bool shouldOwnClient;
		Level lastDiagLevel;
		u32 errorLimits;
		u32 numErrors;
		u32 numWarnings;
		bool hasError;
	};

	class DiagnosticConsumer
	{
	protected:
		u32 numWarnings = 0;
		u32 numErrors = 0;

	public:
		DiagnosticConsumer() = default;
		virtual ~DiagnosticConsumer() = default;

		u32 getNumErrors() const { return numErrors; }
		u32 getNumWarnings() const { return numWarnings; }
		virtual void clear() { numWarnings = numErrors = 0; }

		virtual void handleDiagnostic(DiagnosticInfo info)
		{
			if (info.level == DiagnosticsEngine::Warning)
				++numWarnings;
			else if (info.level >= DiagnosticsEngine::Error)
				++numErrors;
		}
	};

	class SyntaxDiagnosticConsumer : public DiagnosticConsumer
	{
	public:
		static const DiagnosticInfo::DiagnosticTypes type = DiagnosticInfo::SyntaxError;

		void handleDiagnostic(DiagnosticInfo info) override
		{
			CC_LOG_ERROR_NL("{}: {} near token {}, line {}, column {} in file {}",
				info.LevelToString(),
				info.TypeToString(),
				info.token.getRawValue(),
				info.token.line,
				info.token.column,
				info.source.path);
		}
	};
}
