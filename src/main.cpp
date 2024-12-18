#include <iostream>
#include <thread>
#include <chrono>
#include "OrderManager.h"
#include "WebSocketServer.h"
#include "MarketDataHandler.h"
#include "Logger.h"

int main() {
    // Initialize the logger
    Logger::initialize();

    // Create instances of the components
    OrderManager orderManager;
    WebSocketServer wsServer;
    MarketDataHandler marketDataHandler;

    try {
        // Initialize components
        orderManager.initialize();
        wsServer.start();
        marketDataHandler.start();

        std::cout << "System initialized successfully." << std::endl;

        // Main event loop
        while (true) {
            // Here you can handle events, such as incoming WebSocket messages
            // or order management tasks. For now, we will just sleep.
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Example: Check for new market data
            marketDataHandler.processMarketData();

            // Example: Check for new orders
            orderManager.checkPendingOrders();
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}