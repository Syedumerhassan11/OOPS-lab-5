#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> menuItems) {
        name = shopName;
        menu = menuItems;
    }

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "Menu is empty!";
        double minPrice = menu[0].price;
        string cheapest = menu[0].name;
        for (const auto& item : menu) {
            if (item.price < minPrice) {
                minPrice = item.price;
                cheapest = item.name;
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <orders...>\n";
        return 1;
    }

    vector<MenuItem> menu = {
        {"Espresso", "drink", 2.50},
        {"Latte", "drink", 3.50},
        {"Cappuccino", "drink", 3.00},
        {"Muffin", "food", 2.00},
        {"Croissant", "food", 2.75}
    };

    CoffeeShop myShop("Java Haven", menu);

    for (int i = 1; i < argc; i++) {
        cout << myShop.addOrder(argv[i]) << endl;
    }

    cout << "Due Amount: $" << myShop.dueAmount() << endl;

    while (!myShop.listOrders().empty()) {
        cout << myShop.fulfillOrder() << endl;
    }

    cout << "Cheapest Item: " << myShop.cheapestItem() << endl;

    vector<string> drinks = myShop.drinksOnly();
    cout << "Drinks Menu: ";
    for (const auto& drink : drinks) cout << drink << ", ";
    cout << endl;

    vector<string> foods = myShop.foodOnly();
    cout << "Food Menu: ";
    for (const auto& food : foods) cout << food << ", ";
    cout << endl;

    return 0;
}

