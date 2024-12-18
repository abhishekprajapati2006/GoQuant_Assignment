#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <mutex>

// Static member initialization
std::ofstream Logger::logFile;
std::mutex Logger::logMutex;

// Initialize the logger
void Logger::initialize(const std::string& filename) {
    logFile.open(filename, std::ios::app); // Open the log file in append mode
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

// Log a message
void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> guard(logMutex); // Ensure thread safety
    if (logFile.is_open()) {
        logFile << getCurrentTime() << " - " << message << std::endl; // Write to log file
    } else {
        std::cerr << "Log file is not open. Message: " << message << std::endl; // Fallback to console
    }
}

// Get the current time as a string
std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}

// Close the logger
void Logger::close() {
    if (logFile.is_open()) {
        logFile.close(); // Close the log file
    }
}