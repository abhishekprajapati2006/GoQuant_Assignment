#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <mutex>
#include <chrono>
#include <iomanip>

class Logger {
public:
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor
    Logger(const std::string& filename = "", LogLevel level = LogLevel::INFO);

    // Destructor
    ~Logger();

    // Log a message with the specified severity level
    void log(LogLevel level, const std::string& message);

private:
    std::ofstream logFile; // File stream for logging to a file
    LogLevel logLevel;     // Minimum log level to log
    std::mutex logMutex;   // Mutex for thread-safe logging

    // Get the current timestamp as a string
    std::string getCurrentTime() const;

    // Convert LogLevel to string
    std::string logLevelToString(LogLevel level) const;
};

#endif // LOGGER_H