#include "gtest/gtest.h"
#include "OrderManager.h"

// Test fixture for OrderManager tests
class OrderManagerTests : public ::testing::Test {
protected:
    OrderManager orderManager;

    void SetUp() override {
        // Code to set up the test environment, if needed
    }

    void TearDown() override {
        // Code to clean up after tests, if needed
    }
};

// Test case for creating an order
TEST_F(OrderManagerTests, CreateOrder) {
    orderManager.createOrder("AAPL", 10, 150.0);
    Order order = orderManager.getAllOrders().back(); // Get the last order added

    EXPECT_EQ(order.symbol, "AAPL");
    EXPECT_EQ(order.quantity, 10);
    EXPECT_EQ(order.price, 150.0);
    EXPECT_EQ(order.status, OrderStatus::PENDING);
}

// Test case for modifying an order
TEST_F(OrderManagerTests, ModifyOrder) {
    orderManager.createOrder("AAPL", 10, 150.0);
    Order order = orderManager.getAllOrders().back();
    std::string orderId = order.orderId;

    // Modify the order
    bool modified = orderManager.modifyOrder(orderId, 15, 155.0);
    EXPECT_TRUE(modified);

    Order modifiedOrder = orderManager.getAllOrders().back(); // Get the last order added
    EXPECT_EQ(modifiedOrder.quantity, 15);
    EXPECT_EQ(modifiedOrder.price, 155.0);
}

// Test case for canceling an order
TEST_F(OrderManagerTests, CancelOrder) {
    orderManager.createOrder("AAPL", 10, 150.0);
    Order order = orderManager.getAllOrders().back();
    std::string orderId = order.orderId;

    // Cancel the order
    bool canceled = orderManager.cancelOrder(orderId);
    EXPECT_TRUE(canceled);
    EXPECT_EQ(orderManager.getOrderStatus(orderId), OrderStatus::CANCELED);
}

// Test case for getting order status
TEST_F(OrderManagerTests, GetOrderStatus) {
    orderManager.createOrder("AAPL", 10, 150.0);
    Order order = orderManager.getAllOrders().back();
    std::string orderId = order.orderId;

    EXPECT_EQ(orderManager.getOrderStatus(orderId), OrderStatus::PENDING);

    // Cancel the order
    orderManager.cancelOrder(orderId);
    EXPECT_EQ(orderManager.getOrderStatus(orderId), OrderStatus::CANCELED);
}

// Test case for getting all orders
TEST_F(OrderManagerTests, GetAllOrders) {
    orderManager.createOrder("AAPL", 10, 150.0);
    orderManager.createOrder("GOOGL", 5, 2800.0);

    std::vector<Order> orders = orderManager.getAllOrders();
    EXPECT_EQ(orders.size(), 2);
    EXPECT_EQ(orders[0].symbol, "AAPL");
    EXPECT_EQ(orders[1].symbol, "GOOGL");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}