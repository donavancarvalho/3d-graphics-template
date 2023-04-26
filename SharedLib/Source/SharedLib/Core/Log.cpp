#include "Log.h"

namespace SharedLib
{
    std::shared_ptr<Logger> Log::s_CoreLogger;

    void Log::Initialize()
    {
        s_CoreLogger = std::make_shared<Logger>();
        s_CoreLogger->SetLogFile("dc.log");
    }
}