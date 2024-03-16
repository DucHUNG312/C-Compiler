#pragma once

#include "cc/Basic/Version.h"

#ifdef CC_PLATFORM_WINDOWS
#pragma warning(disable : 4251)
#ifdef CC_DYNAMIC
#ifdef CC_ENGINE
#define CC_EXPORT __declspec(dllexport)
#else
#define CC_EXPORT __declspec(dllimport)
#endif
#else
#define CC_EXPORT
#endif
#define CC_HIDDEN
#else
#define CC_EXPORT __attribute__((visibility("default")))
#define CC_HIDDEN __attribute__((visibility("hidden")))
#endif

#ifdef CC_PLATFORM_WINDOWS
#define CC_HAVE__ALIGNED_MALLOC
#endif // CC_PLATFORM_WINDOWS

#ifdef CC_DEBUG_BUILD2
#ifdef CC_PLATFORM_WINDOWS
#define CC_BREAK() __debugbreak()
#else
#define CC_BREAK() raise(SIGTRAP)
#endif
#else
#define CC_BREAK() ""
#endif

#if (defined(_CPPUNWIND) || defined(__EXCEPTIONS))
#define CC_EXCEPTIONS
#endif

#if defined(_MSC_VER)
#define CC_IS_MSVC
#define CC_DISABLE_WARNING_PUSH __pragma(warning(push))
#define CC_DISABLE_WARNING_POP __pragma(warning(pop))
#define CC_DISABLE_WARNING(warningNumber) __pragma(warning(disable \
                                                        : warningNumber))
#define CC_DISABLE_WARNING_UNREFERENCED_FORMAL_PARAMETER CC_DISABLE_WARNING(4100)
#define CC_DISABLE_WARNING_UNREFERENCED_FUNCTION CC_DISABLE_WARNING(4505)
#define CC_DISABLE_WARNING_CONVERSION_TO_SMALLER_TYPE CC_DISABLE_WARNING(4267)
#else
#define CC_DISABLE_WARNING_PUSH
#define CC_DISABLE_WARNING_POP
#define CC_DISABLE_WARNING_UNREFERENCED_FORMAL_PARAMETER
#define CC_DISABLE_WARNING_UNREFERENCED_FUNCTION
#define CC_DISABLE_WARNING_CONVERSION_TO_SMALLER_TYPE
#endif

#pragma once
// comment this to disable profiler
#define CC_ENABLE_PROFILER 0

// comment this to disable logging
#define CC_ENABLE_LOG 1

// enable log
#include "cc/Basic/Log.h"
// Core log macros
#ifdef CC_DEBUG

#endif // CC_DEBUG

#if CC_ENABLE_LOG
#define CC_LOG_TRACE(...) SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::trace, __VA_ARGS__)
#define CC_LOG_DEBUG(...) SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::debug, __VA_ARGS__)
#define CC_LOG_INFO(...) SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::info, __VA_ARGS__)
#define CC_LOG_WARN(...) SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::warn, __VA_ARGS__)
#define CC_LOG_ERROR(...) SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::err, __VA_ARGS__)
#define CC_LOG_CRITICAL(...) SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::critical, __VA_ARGS__)

#define CC_LOG_TRACE_NL(...) (SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::trace, __VA_ARGS__), CC_LOG_TRACE('\n'))
#define CC_LOG_DEBUG_NL(...) (SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::debug, __VA_ARGS__), CC_LOG_TRACE('\n'))
#define CC_LOG_INFO_NL(...) (SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::info, __VA_ARGS__), CC_LOG_TRACE('\n'))
#define CC_LOG_WARN_NL(...) (SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::warn, __VA_ARGS__), CC_LOG_TRACE('\n'))
#define CC_LOG_ERROR_NL(...) (SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::err, __VA_ARGS__), CC_LOG_TRACE('\n'))
#define CC_LOG_CRITICAL_NL(...) (SPDLOG_LOGGER_CALL(::cc::debug::Logger::getCoreLogger(), spdlog::level::level_enum::critical, __VA_ARGS__), CC_LOG_TRACE('\n'))
#else
#define CC_LOG_TRACE(...) ((void)0)
#define CC_LOG_DEBUG(...) ((void)0)
#define CC_LOG_INFO(...) ((void)0)
#define CC_LOG_WARN(...) ((void)0)
#define CC_LOG_ERROR(...) ((void)0)
#define CC_LOG_CRITICAL(...) ((void)0)

#define CC_LOG_TRACE_NL(...) ((void)0)
#define CC_LOG_DEBUG_NL(...) ((void)0)
#define CC_LOG_INFO_NL(...) ((void)0)
#define CC_LOG_WARN_NL(...) ((void)0)
#define CC_LOG_ERROR_NL(...) ((void)0)
#define CC_LOG_CRITICAL_NL(...) ((void)0)
#endif

// enable check
#define CC_ENABLE_CHECK
#ifdef CC_ENABLE_CHECK
#define CHECK(x) (!(!(x) && (CC_LOG_CRITICAL("Check failed: {}", #x), CC_BREAK(), true)))
#define CHECK_MSG(x, msg) (!(!(x) && (CC_LOG_ERROR(#msg), true)))
#define CHECK_ASSERT(x, msg) (!(!(x) && (CC_LOG_CRITICAL(#msg), CC_BREAK(), true)))
#define CHECK_IMPL(a, b, op) (!(!(a op b) && (CC_LOG_CRITICAL("Check failed: {}{}{}", #a, #op, #b), CC_BREAK(), true)))
#define EMPTY_CHECK \
	do {			\
	} while (false);
#define CHECK_EQ(a, b) CHECK_IMPL(a, b, ==)
#define CHECK_NE(a, b) CHECK_IMPL(a, b, !=)
#define CHECK_GT(a, b) CHECK_IMPL(a, b, >)
#define CHECK_GE(a, b) CHECK_IMPL(a, b, >=)
#define CHECK_LT(a, b) CHECK_IMPL(a, b, <)
#define CHECK_LE(a, b) CHECK_IMPL(a, b, <=)

#define CC_CHECK(x) (CHECK(x))
#define CC_CHECK_MSG(x, msg) (CHECK_MSG(x, msg))
#define CC_UNREACHABLE(msg) (CHECK_ASSERT(false, msg))
#define CC_CHECK_EQ(a, b) (CHECK_EQ(a, b))
#define CC_CHECK_NE(a, b) (CHECK_NE(a, b))
#define CC_CHECK_GT(a, b) (CHECK_GT(a, b))
#define CC_CHECK_GE(a, b) (CHECK_GE(a, b))
#define CC_CHECK_LT(a, b) (CHECK_LT(a, b))
#define CC_CHECK_LE(a, b) (CHECK_LE(a, b))
#else
#define CC_CHECK(x) EMPTY_CHECK
#define CC_CHECK_MSG(x, msg) EMPTY_CHECK
#define CC_CHECK_ASSERT(x, msg) EMPTY_CHECK
#define CC_CHECK_EQ(a, b) EMPTY_CHECK
#define CC_CHECK_NE(a, b) EMPTY_CHECK
#define CC_CHECK_GT(a, b) EMPTY_CHECK
#define CC_CHECK_GE(a, b) EMPTY_CHECK
#define CC_CHECK_LT(a, b) EMPTY_CHECK
#define CC_CHECK_LE(a, b) EMPTY_CHECK
#endif // CC_ENABLE_CHECK

// Profiler
#define EMPTY_PROFILE \
	do {			  \
	} while (false);
#if CC_ENABLE_PROFILER
#ifdef CC_PLATFORM_WINDOWS
#define TRACY_CALLSTACK 1
#endif

#define CC_TRACK_MEMORY 1
#define CC_PROFILE_LOW 0

#include <tracy/Tracy.hpp>
#define CC_PROFILE_SCOPE(name) ZoneScopedN(name)
#define CC_PROFILE_FUNCTION() ZoneScoped
#define CC_PROFILE_FRAMEMARKER() FrameMark
#define CC_PROFILE_LOCK(type, var, name) TracyLockableN(type, var, name)
#define CC_PROFILE_LOCKMARKER(var) LockMark(var)
#define CC_PROFILE_SETTHREADNAME(name) tracy::SetThreadName(name)

#if CC_PROFILE_LOW
#define CC_PROFILE_FUNCTION_LOW() ZoneScoped
#define CC_PROFILE_SCOPE_LOW(name) ZoneScopedN(name)
#else
#define CC_PROFILE_FUNCTION_LOW()
#define CC_PROFILE_SCOPE_LOW(name)
#endif

#else
#define CC_PROFILE_SCOPE(name) EMPTY_PROFILE
#define CC_PROFILE_FUNCTION() EMPTY_PROFILE
#define CC_PROFILE_FRAMEMARKER() EMPTY_PROFILE
#define CC_PROFILE_LOCK(type, var, name) EMPTY_PROFILE
#define CC_PROFILE_LOCKMARKER(var) EMPTY_PROFILE
#define CC_PROFILE_SETTHREADNAME(name) EMPTY_PROFILE
#define CC_PROFILE_FUNCTION_LOW() EMPTY_PROFILE
#define CC_PROFILE_SCOPE_LOW(name) EMPTY_PROFILE
#endif

#ifndef CC_UNIMPLEMENTED
#define CC_UNIMPLEMENTED									            \
	CC_LOG_CRITICAL("Unimplemented : {} : {}", __FILE__, __LINE__);	\
	CC_BREAK()
#endif // !CC_UNIMPLEMENTED


#define CC_NONCOPYABLE(class_name)                           \
    class_name(const class_name&)            = delete;		  \
    class_name& operator=(const class_name&) = delete;
#define CC_NONCOPYABLEANDMOVE(class_name)                    \
    class_name(const class_name&)            = delete;		  \
    class_name& operator=(const class_name&) = delete;		  \
    class_name(class_name&&)                 = delete;		  \
    class_name& operator=(class_name&&)      = delete;



#ifndef CC_FORCE_INLINE
#if defined(_MSC_VER)
#define CC_FORCE_INLINE __forceinline
#else
#define CC_FORCE_INLINE inline
#endif
#endif // !CC_FORCE_INLINE

#ifndef CC_ALWAYS_INLINE
#if defined(_MSC_VER)
#define CC_ALWAYS_INLINE CC_FORCE_INLINE
#else
#define CC_ALWAYS_INLINE inline
#endif 
#endif // !CC_ALWAYS_INLINE

#ifndef CC_NODISCARD
#define CC_NODISCARD [[nodiscard]]
#endif // !CC_NODISCARD

#ifndef CC_ALLOW_DISCARD
#define CC_ALLOW_DISCARD (void)
#endif // !CC_ALLOW_DISCARD

#if defined(_MSC_VER)
// NOTE MSVC often gives C4127 warnings with compiletime if statements. See bug 1362.
// This workaround is ugly, but it does the job.
#define CC_CONST_CONDITIONAL(cond)  (void)0, cond
#else
#define CC_CONST_CONDITIONAL(cond)  cond
#endif

// Define Cache Line Size Constant
#ifndef CC_L1_CACHE_LINE_SIZE
#define CC_L1_CACHE_LINE_SIZE 64
#endif

#ifndef CC_STR
#define CC_STR(x) #x
#define CC_MAKE_STR(x) STR(x)
#endif // !CC_STR

#ifndef CC_MAX_RECURSION
#define CC_MAX_RECURSION 100
#endif // CC_MAX_RECURSION

#ifndef CC_BIT
#define CC_BIT(x) (1 << x)
#endif // !CC_BIT

#ifndef CC_SHIFT_LEFT
#define CC_SHIFT_LEFT(x) (size_t(1) << x)
#endif // 

#ifndef CC_SHIFT_RIGHT
#define CC_SHIFT_RIGHT(x) (size_t(1) >> x)
#endif // !CC_SHIFT_RIGHT

