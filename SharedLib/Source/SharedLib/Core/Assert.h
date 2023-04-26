#pragma once
#include "SharedLib/Core/Log.h"

#ifdef DC_DEBUG
#define DC_ENABLE_ASSERTS
#endif

#ifdef DC_ENABLE_ASSERTS
#define DC_ASSERT_INTERNAL_MESSAGE(...) SharedLib::Log::GetCoreLogger()->Assert(__FILE__, __LINE__, __VA_ARGS__)
#define DC_ASSERT(condition, ...)                \
    if (!condition)                              \
    {                                            \
        DC_ASSERT_INTERNAL_MESSAGE(__VA_ARGS__); \
        std::abort();                            \
    }
#else
#define DC_ASSERT(...)
#endif