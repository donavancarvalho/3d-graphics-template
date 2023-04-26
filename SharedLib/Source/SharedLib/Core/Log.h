#pragma once
#include "SharedLib/Core/Logger.h"
#include <memory>

namespace SharedLib
{
    class Log
    {
    public:
        void Initialize();

        static std::shared_ptr<Logger> &GetCoreLogger() { return s_CoreLogger; }

    private:
        static std::shared_ptr<Logger> s_CoreLogger;
    };
}

#ifdef DC_DEBUG
#define DC_LOG(...) SharedLib::Log::GetCoreLogger()->Log(__VA_ARGS__)
#define DC_ERROR(...) SharedLib::Log::GetCoreLogger()->Error(__VA_ARGS__)
#define DC_FATAL(...) SharedLib::Log::GetCoreLogger()->Fatal(__VA_ARGS__)
#define DC_INFO(...) SharedLib::Log::GetCoreLogger()->Info(__VA_ARGS__)
#define DC_SUCCESS(...) SharedLib::Log::GetCoreLogger()->Success(__VA_ARGS__)
#define DC_TRACE(...) SharedLib::Log::GetCoreLogger()->Trace(__VA_ARGS__)
#define DC_WARNING(...) SharedLib::Log::GetCoreLogger()->Warning(__VA_ARGS__)
#else
#define DC_LOG(...)
#define DC_ERROR(...)
#define DC_FATAL(...)
#define DC_INFO(...)
#define DC_SUCCESS(...)
#define DC_TRACE(...)
#define DC_WARNING(...)
#endif