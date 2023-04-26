#include "SharedLib/Core/Log.h"
#include "SharedLib/Core/Assert.h"

int main()
{
    std::unique_ptr<SharedLib::Log> log = std::make_unique<SharedLib::Log>();
    log->Initialize();

#ifdef DC_DEBUG
    DC_LOG("{0}", "Debug Mode");
#else
    DC_LOG("{0}", "Release Mode");
#endif
    DC_ERROR("message!!!");
    DC_FATAL("message!!!");
    DC_INFO("message!!!");
    DC_SUCCESS("message!!!");
    DC_TRACE("message!!!");
    DC_WARNING("message!!!");

    DC_ASSERT(false, "{0}", "Failed");

    return 0;
}