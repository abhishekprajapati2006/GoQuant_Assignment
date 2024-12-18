#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

#include <string>

// Function to create a socket and connect to a server
int createSocketAndConnect(const std::string& ip, int port);

// Function to send data over a socket
bool sendData(int sock, const std::string& data);

// Function to receive data from a socket
std::string receiveData(int sock);

// Function to close a socket
void closeSocket(int sock);

#endif // NETWORK_UTILS_H