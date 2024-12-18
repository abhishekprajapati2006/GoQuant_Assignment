#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

// Enum for order status
enum class OrderStatus {
    PENDING,
    FILLED,
    CANCELED,
    REJECTED
};

// Structure to represent an order
struct Order {
    std::string orderId;      // Unique identifier for the order
    std::string symbol;       // Trading symbol (e.g., "AAPL")
    double quantity;          // Quantity of the asset to buy/sell
    double price;             // Price at which to buy/sell
    OrderStatus status;       // Current status of the order
};

// Class to manage orders
class OrderManager {
public:
    // Create a new order
    void createOrder(const std::string& symbol, double quantity, double price);

    // Modify an existing order
    bool modifyOrder(const std::string& orderId, double newQuantity, double newPrice);

    // Cancel an existing order
    bool cancelOrder(const std::string& orderId);

    // Get the status of an order
    OrderStatus getOrderStatus(const std::string& orderId) const;

    // Get a list of all orders
    std::vector<Order> getAllOrders() const;

private:
    std::unordered_map<std::string, Order> orders; // Map to store orders by orderId
};

#endif // ORDER_MANAGER_H