#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

// Forward declaration of WebSocket connection class
class WebSocketConnection;

// Class to manage a WebSocket server
class WebSocketServer {
public:
    // Constructor
    WebSocketServer(int port);

    // Start the WebSocket server
    void start();

    // Stop the WebSocket server
    void stop();

    // Set a callback for handling incoming messages
    void setMessageHandler(std::function<void(const std::string&, const std::string&)> handler);

private:
    int port;  // Port number for the WebSocket server
    bool running;  // Flag to indicate if the server is running
    std::unordered_map<std::string, WebSocketConnection*> connections; // Active connections
    std::function<void(const std::string&, const std::string&)> messageHandler; // Message handler callback

    // Function to accept new connections
    void acceptConnections();

    // Function to handle incoming messages
    void handleMessage(const std::string& connectionId, const std::string& message);

    // Function to remove a connection
    void removeConnection(const std::string& connectionId);
};

#endif // WEBSOCKET_SERVER_H