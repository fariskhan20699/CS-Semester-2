#include <iostream>
using namespace std;

class Product {
protected:
    int id;
    string name;
    double price;
    int stock;

public:
    Product(int i, string n, double p, int s)
        : id(i), name(n), price(p), stock(s) {}

    virtual void display() = 0;
    virtual int getId() { return id; }
    virtual string getName() { return name; }
    virtual double getPrice() { return price; }

    virtual void reduceStock(int qty) {
        stock -= qty;
    }

    virtual int getStock() {
        return stock;
    }

    virtual ~Product() {}
};

class Item : public Product {
public:
    Item(int i, string n, double p, int s)
        : Product(i, n, p, s) {}

    void display() override {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: " << price
             << " | Stock: " << stock << endl;
    }
};

class Shop {
private:
    Item* products[10];
    int count;

public:
    Shop() { count = 0; }

    void addProduct(Item* p) {
        if (count < 10) {
            products[count++] = p;
        } else {
            cout << "Shop full!\n";
        }
    }

    void showProducts() {
        cout << "\n--- PRODUCTS ---\n";
        for (int i = 0; i < count; i++) {
            products[i]->display();
        }
    }

    // ================= BILL GENERATOR =================
    void generateBill(int id, int qty) {
        for (int i = 0; i < count; i++) {
            if (products[i]->getId() == id) {

                if (qty > products[i]->getStock()) {
                    cout << "Not enough stock!\n";
                    return;
                }

                double total = qty * products[i]->getPrice();

                products[i]->reduceStock(qty);

                cout << "\n====== BILL ======\n";
                cout << "Product: " << products[i]->getName() << endl;
                cout << "Quantity: " << qty << endl;
                cout << "Price per item: " << products[i]->getPrice() << endl;
                cout << "TOTAL BILL: " << total << endl;
                cout << "==================\n";

                return;
            }
        }

        cout << "Product not found!\n";
    }
};

int main() {
    Shop shop;

    shop.addProduct(new Item(1, "Milk", 200, 10));
    shop.addProduct(new Item(2, "Bread", 50, 20));
    shop.addProduct(new Item(3, "Sugar", 150, 15));

    int choice;

    while (true) {
        cout << "\n===== SHOP MENU =====\n";
        cout << "1. Show Products\n";
        cout << "2. Generate Bill\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            shop.showProducts();
        }
        else if (choice == 2) {
            int id, qty;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> qty;

            shop.generateBill(id, qty);
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
