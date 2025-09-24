/*
(Invoice Class) Create a class called Invoice that a hardware store might use to represent an invoice for an item sold at the store. An Invoice should include four data members—a part num- ber (type string), a part description (type string), a quantity of the item being purchased (type int) and a price per item (type int). [Note: In subsequent chapters, we’ll use numbers that contain decimal points (e.g., 2.75)—called floating-point values—to represent dollar amounts.] Your class should have a constructor that initializes the four data members. Provide a set and a get function for each data member. In addition, provide a member function named getInvoiceAmount that calcu- lates the invoice amount (i.e., multiplies the quantity by the price per item), then returns the amount as an int value. If the quantity is not positive, it should be set to 0. If the price per item is not positive, it should be set to 0. Write a test program that demonstrates class Invoice’s capabilities.
*/

#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    int pricePerItem;

public:
    // constructor
    Invoice(string number, string description, int qty, int price) {
        partNumber = number;
        partDescription = description;
        if (qty > 0) {
            quantity = qty;
        } else {
            quantity = 0;
        }
        if (price > 0) {
            pricePerItem = price;
        } else {
            pricePerItem = 0;
        }
    }

    // setters
    void setPartNumber(string number) { partNumber = number; }
    void setPartDescription(string description) { partDescription = description; }
    void setQuantity(int qty) { quantity = (qty > 0 ? qty : 0); }
    void setPricePerItem(int price) { pricePerItem = (price > 0 ? price : 0); }

    // getters
    string getPartNumber() const { return partNumber; }
    string getPartDescription() const { return partDescription; }
    int getQuantity() const { return quantity; }
    int getPricePerItem() const { return pricePerItem; }

    // calculate invoice amount
    int getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    // create invoice objects
    Invoice item1("A101", "Hammer", 5, 50);
    Invoice item2("B202", "Nails Box", -3, 20); // invalid quantity, will be set to 0

    // display invoices
    cout << "Item 1: " << item1.getPartDescription()
         << " (Part " << item1.getPartNumber() << ")" << endl;
    cout << "Quantity: " << item1.getQuantity()
         << ", Price per item: " << item1.getPricePerItem()
         << ", Total: " << item1.getInvoiceAmount() << endl;

    cout << "\nItem 2: " << item2.getPartDescription()
         << " (Part " << item2.getPartNumber() << ")" << endl;
    cout << "Quantity: " << item2.getQuantity()
         << ", Price per item: " << item2.getPricePerItem()
         << ", Total: " << item2.getInvoiceAmount() << endl;

    // update second invoice to valid values
    item2.setQuantity(10);
    item2.setPricePerItem(15);

    cout << "\nAfter update -> Item 2 total: " << item2.getInvoiceAmount() << endl;

    return 0;
}
