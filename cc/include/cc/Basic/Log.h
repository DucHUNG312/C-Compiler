#pragma once

#include "cc/Basic/PCH.h"

#define SPDLOG_EOL ""
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace cc::debug
{
	class Logger
	{
	public:
		static void init();
		static void release();
		static std::shared_ptr<spdlog::logger>& getCoreLogger() { return CoreLogger; }
		static void addSink(std::shared_ptr<spdlog::sinks::sink>& Sink);
	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
	};
}
