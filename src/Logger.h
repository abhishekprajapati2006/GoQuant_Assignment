#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

class Logger {
public:
    // Initialize the logger with a specified log file
    static void initialize(const std::string& filename);

    // Log a message
    static void log(const std::string& message);

    // Close the logger
    static void close();

private:
    // Get the current time as a string
    static std::string getCurrentTime();

    // Static members for file handling and thread safety
    static std::ofstream logFile; // Log file stream
    static std::mutex logMutex;   // Mutex for thread safety
};

#endif // LOGGER_H