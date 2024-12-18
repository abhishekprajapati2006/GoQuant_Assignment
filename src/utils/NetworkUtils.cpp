#include "NetworkUtils.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to create a socket and connect to a server
int createSocketAndConnect(const std::string& ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Could not create socket" << std::endl;
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &server.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        close(sock);
        return -1;
    }

    return sock; // Return the socket descriptor
}

// Function to send data over a socket
bool sendData(int sock, const std::string& data) {
    ssize_t sentBytes = send(sock, data.c_str(), data.size(), 0);
    if (sentBytes == -1) {
        std::cerr << "Failed to send data" << std::endl;
        return false;
    }
    return true;
}

// Function to receive data from a socket
std::string receiveData(int sock) {
    char buffer[1024] = {0};
    ssize_t receivedBytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (receivedBytes == -1) {
        std::cerr << "Failed to receive data" << std::endl;
        return "";
    }
    buffer[receivedBytes] = '\0'; // Null-terminate the received data
    return std::string(buffer);
}

// Function to close a socket
void closeSocket(int sock) {
    if (close(sock) == -1) {
        std::cerr << "Failed to close socket" << std::endl;
    }
}