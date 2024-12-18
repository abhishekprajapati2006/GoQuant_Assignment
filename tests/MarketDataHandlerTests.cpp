#include "gtest/gtest.h"
#include "MarketDataHandler.h"

// Test fixture for MarketDataHandler tests
class MarketDataHandlerTests : public ::testing::Test {
protected:
    MarketDataHandler marketDataHandler;

    void SetUp() override {
        // Code to set up the test environment, if needed
    }

    void TearDown() override {
        // Code to clean up after tests, if needed
    }
};

// Test case for subscribing to market data
TEST_F(MarketDataHandlerTests, Subscribe) {
    marketDataHandler.subscribe("AAPL");
    // Assuming we have a way to check subscriptions, we can verify here
    // This would require modifying the MarketDataHandler class to expose subscriptions
}

// Test case for unsubscribing from market data
TEST_F(MarketDataHandlerTests, Unsubscribe) {
    marketDataHandler.subscribe("AAPL");
    marketDataHandler.unsubscribe("AAPL");
    // Verify that the subscription has been removed
    // This would require modifying the MarketDataHandler class to expose subscriptions
}

// Test case for processing market data
TEST_F(MarketDataHandlerTests, ProcessMarketData) {
    marketDataHandler.subscribe("AAPL");
    marketDataHandler.setMarketDataCallback([](const MarketData& data) {
        EXPECT_EQ(data.symbol, "AAPL");
        EXPECT_EQ(data.price, 150.0);
        EXPECT_EQ(data.volume, 1000.0);
    });

    // Simulate incoming market data
    marketDataHandler.processMarketData("AAPL", 150.0, 1000.0);
}

// Test case for getting the latest market data
TEST_F(MarketDataHandlerTests, GetLatestMarketData) {
    marketDataHandler.subscribe("AAPL");
    marketDataHandler.processMarketData("AAPL", 150.0, 1000.0);
    
    MarketData latestData = marketDataHandler.getLatestMarketData("AAPL");
    EXPECT_EQ(latestData.symbol, "AAPL");
    EXPECT_EQ(latestData.price, 150.0);
    EXPECT_EQ(latestData.volume, 1000.0);
}

// Test case for getting market data for an unsubscribed symbol
TEST_F(MarketDataHandlerTests, GetMarketDataForUnsubscribedSymbol) {
    MarketData latestData = marketDataHandler.getLatestMarketData("AAPL");
    EXPECT_EQ(latestData.symbol, "AAPL");
    EXPECT_EQ(latestData.price, 0