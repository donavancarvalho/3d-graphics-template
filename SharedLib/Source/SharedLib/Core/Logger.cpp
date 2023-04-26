#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <iostream>

namespace SharedLib
{
    std::string Logger::GetLogTypeString(LogType type)
    {
        switch (type)
        {
        case LogType::Assert:
            return "Assertion Error";
        case LogType::Error:
            return "Error";
        case LogType::Fatal:
            return "Fatal";
        case LogType::Info:
            return "Info";
        case LogType::Log:
            return "Log";
        case LogType::Success:
            return "Success";
        case LogType::Trace:
            return "Trace";
        case LogType::Warning:
            return "Warning";
        }

        return "";
    }

    std::string Logger::GetLogColor(LogType type)
    {
        switch (type)
        {
        case LogType::Error:
            return "\033[91m";
        case LogType::Assert:
        case LogType::Fatal:
            return "\033[31m";
        case LogType::Info:
            return "\033[34m";
        case LogType::Success:
            return "\033[92m";
        case LogType::Trace:
            return "\033[35m";
        case LogType::Warning:
            return "\033[93m";
        }

        // Log uses default color (white)
        return "";
    }

    Logger::Logger() : m_Filepath(""), m_HasLogFile(false) {}

    void Logger::SetLogFile(const std::string &filepath)
    {
        if (filepath.size() > 0)
        {
            m_HasLogFile = true;
            m_Filepath = filepath;
        }
        else
        {
            m_HasLogFile = false;
            m_Filepath = "";
        }
    }

    void Logger::PrintLine(std::string message)
    {
        std::cout << message << '\n';
    }

    std::string Logger::GetCurrentDatetime(std::string format)
    {
        auto now = std::chrono::system_clock::now();

        auto inTime = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;

        std::tm *tm = localtime(&inTime);

        ss << std::put_time(tm, format.c_str());
        return ss.str();
    }
}