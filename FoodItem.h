#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <string>

class FoodItem {
private:
    std::string name;
    int daysToExpiration;
    double quantity;

public:
    // Default constructor (Needed for container operations)
    FoodItem() : name(""), daysToExpiration(0), quantity(0.0) {}

    // Overloaded Constructor for proper initialization
    FoodItem(std::string p_name, int p_days, double p_qty);

    // Getters and Setters ensuring true Encapsulation
    std::string getName() const;
    int getDaysToExpiration() const;
    double getQuantity() const;
    void setQuantity(double p_qty);

    // Logical Behaviors
    void reduceDays();
    bool isSpoiled() const;
    double getWasteRiskScore() const;
};

#endif
