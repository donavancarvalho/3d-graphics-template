#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace SharedLib
{
    enum class LogType
    {
        None = 0,
        Assert,
        Error,
        Fatal,
        Info,
        Log,
        Success,
        Trace,
        Warning
    };

    class Logger
    {
    public:
        Logger();
        ~Logger() = default;

        void SetLogFile(const std::string &filepath);

        template <typename... Args>
        void PrintFormattedMessage(LogType type, std::string format, Args... args)
        {
            std::string message = FormatMessage(format, args...);
            std::string outputMessage;

            if (type == LogType::None)
            {
                outputMessage = GetCurrentDatetime("[%m/%d/%y %H:%M:%S]") + " " + message;
            }
            else
            {
                outputMessage = GetCurrentDatetime("[%m/%d/%y %H:%M:%S]") + " " + GetLogTypeString(type) + ": " + message;
            }

            PrintLine(GetLogColor(type) + outputMessage + "\033[0m");

            if (m_HasLogFile)
            {
                std::ofstream file;
                file.open(m_Filepath, std::ios_base::app);

                if (file.is_open())
                {
                    file << outputMessage << '\n';
                    file.close();
                }
            }
        }

        template <typename... Args>
        void Assert(std::string file, int line, std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Assert, format + " (" + file + ":" + std::to_string(line) + ")", args...);
        }

        template <typename... Args>
        void Error(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Error, format, args...);
        }

        template <typename... Args>
        void Fatal(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Fatal, format, args...);
        }

        template <typename... Args>
        void Info(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Info, format, args...);
        }

        template <typename... Args>
        void Log(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Log, format, args...);
        }

        template <typename... Args>
        void Success(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Success, format, args...);
        }

        template <typename... Args>
        void Trace(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Trace, format, args...);
        }

        template <typename... Args>
        void Warning(std::string format, Args... args)
        {
            PrintFormattedMessage(LogType::Warning, format, args...);
        }

    private:
        std::string GetCurrentDatetime(std::string format);
        std::string GetLogTypeString(LogType type);
        std::string GetLogColor(LogType type);
        void PrintLine(std::string message);

        template <typename T>
        std::string ToString(const T &value)
        {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }

        template <typename... Args>
        std::string FormatMessage(const std::string &format, Args... args)
        {
            std::string message = format;
            int argIndex = 0;
            std::ostringstream argumentString;
            std::vector<std::string> arguments;

            (void)std::initializer_list<int>{(argumentString.str(""), argumentString << ToString(args),
                                              arguments.push_back(argumentString.str()), argIndex++, 0)...};

            size_t pos;
            for (int i = 0; i < arguments.size(); ++i)
            {
                pos = message.find("{" + std::to_string(i) + "}");

                if (pos != std::string::npos)
                {
                    message.replace(pos, 3, arguments[i]);
                }
            }

            return message;
        }

    private:
        bool m_HasLogFile;
        std::string m_Filepath;
    };
}