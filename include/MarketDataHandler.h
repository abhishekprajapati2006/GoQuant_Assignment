#ifndef MARKET_DATA_HANDLER_H
#define MARKET_DATA_HANDLER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <functional>

// Structure to represent market data for a specific symbol
struct MarketData {
    std::string symbol;      // Trading symbol (e.g., "AAPL")
    double price;            // Current price of the asset
    double volume;           // Trading volume
    // Additional fields can be added as needed (e.g., bid, ask, timestamp)
};

// Class to handle market data
class MarketDataHandler {
public:
    // Constructor
    MarketDataHandler();

    // Subscribe to market data for a specific symbol
    void subscribe(const std::string& symbol);

    // Unsubscribe from market data for a specific symbol
    void unsubscribe(const std::string& symbol);

    // Set a callback for processing incoming market data
    void setMarketDataCallback(std::function<void(const MarketData&)> callback);

    // Process incoming market data
    void processMarketData(const std::string& symbol, double price, double volume);

    // Get the latest market data for a specific symbol
    MarketData getLatestMarketData(const std::string& symbol) const;

private:
    std::unordered_map<std::string, MarketData> marketDataMap; // Map to store market data by symbol
    std::function<void(const MarketData&)> marketDataCallback; // Callback for market data processing
};

#endif // MARKET_DATA_HANDLER_H