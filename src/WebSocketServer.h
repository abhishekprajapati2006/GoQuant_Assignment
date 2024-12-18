#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <string>

class WebSocketServer {
public:
    // Constructor
    WebSocketServer();

    // Start the WebSocket server
    void start();

    // Handle incoming connections
    void onConnection(int clientId);

    // Handle incoming messages
    void onMessage(int clientId, const std::string& message);

    // Send a message to a client
    void sendMessage(int clientId, const std::string& message);

    // Handle client disconnection
    void onDisconnect(int clientId);

private:
    // You can add private member variables here, such as:
    // std::map<int, std::shared_ptr<WebSocket>> clients; // Example for storing connected clients
    // int nextClientId; // To keep track of the next client ID
};

#endif // WEBSOCKET_SERVER_H