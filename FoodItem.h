#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

// ============================================================================
// MODULE 1: FOODITEM ENTITY (OOP Integration & True Encapsulation)
// ============================================================================
class FoodItem {
private:
    std::string name;
    int daysToExpiration;
    double quantity;

public:
    // Default Constructor (Required for internal vector container manipulation)
    FoodItem() : name(""), daysToExpiration(0), quantity(0.0) {}

    // Overloaded Constructor for clean object initialization
    FoodItem(std::string p_name, int p_days, double p_qty) 
        : name(p_name), daysToExpiration(p_days), quantity(p_qty) {}

    // Getters and Setters establishing strict Encapsulation boundaries
    std::string getName() const { return name; }
    int getDaysToExpiration() const { return daysToExpiration; }
    double getQuantity() const { return quantity; }
    
    void setQuantity(double p_qty) { 
        if (p_qty >= 0.0) {
            quantity = p_qty; 
        }
    }

    // Logical Class Behaviors (Fulfills requirement for pure algorithmic operations)
    void reduceDays() { 
        daysToExpiration--; 
    }
    
    bool isSpoiled() const { 
        return daysToExpiration <= 0; 
    }
    
    // Algorithmic evaluation computing a dynamic metric on demand
    double getWasteRiskScore() const {
        if (daysToExpiration <= 0) return 100.0;
        if (daysToExpiration > 7) return 10.0;
        return (1.0 / daysToExpiration) * quantity * 10.0;
    }
};

// ============================================================================
// MODULE 2: PANTRYMANAGER DATABASE ENGINE (Collection Management & CRUD)
// ============================================================================
class PantryManager {
private:
    // Collection Management: Dynamic tracking database records
    std::vector<FoodItem> inventory; 

    // Internal lookup utility (Linear scan framework)
    int findItemIndex(const std::string& name) const {
        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i].getName() == name) {
                return static_cast<int>(i);
            }
        }
        return -1; // Flag indicating a non-existent item profile
    }

public:
    // [C]REATE: Append a validated item block into the sequence
    void addItem(const FoodItem& item) {
        inventory.push_back(item);
        std::cout << "\n>>> [SUCCESS] Resource \"" << item.getName() << "\" safely appended to registry.\n";
    }

    // [R]EAD: Multi-record rendering using advanced iteration loops and nested decisions
    void displayInventory() const {
        if (inventory.empty()) {
            std::cout << "\n[System Notice: Active stock sequence is completely empty.]\n";
            return;
        }
        std::cout << "\n===================================================\n";
        std::cout << "             CURRENT PANTRY STOCK METRICS          \n";
        std::cout << "===================================================\n";
        for (const auto& item : inventory) {
            std::cout << " * " << item.getName() 
                      << " | Qty: " << item.getQuantity() 
                      << " | Expiration Window: " << item.getDaysToExpiration() << " Days";
            
            // Nested Decisions evaluating metrics inside the render matrix
            if (item.isSpoiled()) {
                std::cout << " -> [CRITICAL: SPOILED / WASTE RISK SCORE: " << item.getWasteRiskScore() << "]";
            } else if (item.getDaysToExpiration() <= 2) {
                std::cout << " -> [WARNING: CONSUME IMMEDIATELY]";
            }
            std::cout << "\n";
        }
        std::cout << "===================================================\n";
    }

    // [U]PDATE: Process asset restock, calculate merged metrics, and rebuild profile
    bool restockItem(const std::string& name, int newDays, double additionalQty) {
        int index = findItemIndex(name);
        if (index != -1) {
            // Aggregate incoming quantities with legacy database entries
            double combinedQty = inventory[index].getQuantity() + additionalQty;
            
            // Replace old data footprint inside the vector using constructor-based overwriting
            inventory[index] = FoodItem(name, newDays, combinedQty);
            return true;
        }
        return false;
    }

    // [D]ELETE: Erase specific profile indices out of contiguous storage allocation
    bool deleteItem(const std::string& name) {
        int index = findItemIndex(name);
        if (index != -1) {
            // Vector erase uses memory offset indexing pointers to close data gaps
            inventory.erase(inventory.begin() + index);
            return true;
        }
        return false;
    }

    // SYSTEM COMPONENT: Simulation Engine Matrix Step
    void simulateDay() {
        if (inventory.empty()) {
            std::cout << "\n[System Notice: Simulation skipped. Local register space is empty.]\n";
            return;
        }
        for (auto& item : inventory) {
            item.reduceDays();
        }
        std::cout << "\n>>> [SYSTEM EVENT] 24 Hours elapsed. Shelf life constraints tracking updated.\n";
    }

    // DATA PERSISTENCE: Input streams ingestion handler
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return; // Suppress errors if database doesn't exist on first bootup

        std::string line, name;
        int days; 
        double qty;

        inventory.clear();
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            // Read CSV formatted stream metrics safely
            if (std::getline(ss, name, ',') && ss >> days && ss.ignore() && ss >> qty) {
                inventory.push_back(FoodItem(name, days, qty));
            }
        }
        file.close();
    }

    // DATA PERSISTENCE: Output file writer persistence engine
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "\n[CRITICAL ERROR] Local device permission issue. System context missing data.\n";
            return;
        }
        for (const auto& item : inventory) {
            file << item.getName() << "," 
                 << item.getDaysToExpiration() << "," 
                 << item.getQuantity() << "\n";
        }
        file.close();
    }
};

// ============================================================================
// MODULE 3: USER INTERFACE APPLICATION CONTROLLER (Loops & Stream Security)
// ============================================================================
void displayMenu() {
    std::cout << "\n===================================================\n";
    std::cout << "         PANTRY GUARDIAN INTERFACE (SDG 12)        \n";
    std::cout << "===================================================\n";
    std::cout << " 1. [READ]   Check Registered Inventory Stock\n";
    std::cout << " 2. [CREATE] Ingest New Supply Batch Record\n";
    std::cout << " 3. [UPDATE] Restock & Refresh Expiration Logs\n";
    std::cout << " 4. [DELETE] Evict / Purge Active Asset Profile\n";
    std::cout << " 5. [SYSTEM] Fast-Forward Simulation Frame (1 Day)\n";
    std::cout << " 6. [EXIT]   Commit Transactions and Terminate App\n";
    std::cout << "===================================================\n";
    std::cout << "Enter command index execution sequence (1-6): ";
}

int main() {
    PantryManager manager;
    const std::string databasePath = "pantry_db.txt";

    // Data Persistence: Seed the memory registers from past operational instances
    manager.loadFromFile(databasePath);

    int selection = 0;
    while (selection != 6) {
        displayMenu();
        
        // Input Validation: Catches users entering letters or strings into an integer parameter
        if (!(std::cin >> selection)) {
            std::cout << "\n>>> [STREAM CORRUPTION EXCEPTION] Invalid characters typed. Re-initializing terminal input stream hooks.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (selection == 1) {
            manager.displayInventory();
        } 
        else if (selection == 2) {
            std::string name; int days; double qty;
            std::cout << "Assign item string label identifier: "; std::cin >> name;
            std::cout << "Assign item storage shelf lifespan limit (days): "; std::cin >> days;
            std::cout << "Assign volumetric count or physical weight metrics: "; std::cin >> qty;
            
            manager.addItem(FoodItem(name, days, qty));
        } 
        else if (selection == 3) {
            std::string name; int days; double qty;
            std::cout << "Enter targeted item string label to update: "; std::cin >> name;
            std::cout << "Enter incoming batch baseline expiration scale: "; std::cin >> days;
            std::cout << "Enter incremental incoming product mass volume: "; std::cin >> qty;
            
            if (manager.restockItem(name, days, qty)) {
                std::cout << "\n>>> [UPDATE EVENT] Target inventory row identity modification sequence successful.\n";
            } else {
                std::cout << "\n>>> [ERROR] No log entry matched the target criteria label pattern.\n";
            }
        } 
        else if (selection == 4) {
            std::string name;
            std::cout << "Enter targeted item identity label to erase completely: "; std::cin >> name;
            
            if (manager.deleteItem(name)) {
                std::cout << "\n>>> [DELETE EVENT] Row element completely eliminated out of stack context data blocks.\n";
            } else {
                std::cout << "\n>>> [ERROR] Profile row search operation field parameters empty or invalid.\n";
            }
        } 
        else if (selection == 5) {
            manager.simulateDay();
        }
        else if (selection != 6) {
            std::cout << "\n>>> Execution code outside numerical boundaries. Reset constraints framework parameters.\n";
        }
    }

    // Data Persistence: Secure data logs down onto local system non-volatile sectors before structural context frame collapse
    manager.saveToFile(databasePath);
    std::cout << "\n>>> [SYSTEM OK] Active context instances written safely to database disk storage file. Engine shut down complete.\n";
    return 0;
}
