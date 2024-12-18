#ifndef MARKET_DATA_HANDLER_H
#define MARKET_DATA_HANDLER_H

#include <string>
#include <map>

// Struct to represent market data
struct MarketData {
    std::string symbol;
    double price;
    double volume;
};

class MarketDataHandler {
public:
    // Constructor
    MarketDataHandler();

    // Subscribe to market data for a specific symbol
    void subscribe(const std::string& symbol);

    // Unsubscribe from market data for a specific symbol
    void unsubscribe(const std::string& symbol);

    // Process incoming market data messages
    void processMarketData(const std::string& message);

    // Get the latest market data for a specific symbol
    MarketData getLatestMarketData(const std::string& symbol);

private:
    // Update internal market data storage
    void updateMarketData(const MarketData& data);

    // Internal storage for market data
    std::map<std::string, MarketData> marketDataStore; // Maps symbol to MarketData
};

#endif // MARKET_DATA_HANDLER_H