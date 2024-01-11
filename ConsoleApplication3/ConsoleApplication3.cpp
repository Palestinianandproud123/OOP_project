#include<iostream>
#include<iomanip>
#include<fstream>
#include"Interface_cash.h"
#include"Interface_PhoneSectionType.h"
#include"Interface_TrollyType.h"
#include"Interface_productType.h"
using namespace std;
int main() {
    string name;
    float price;
    PhoneSectionType section1;
    TrollyType trolly;
    int select_item;
    int quantity;
    int productNumber = 0;
    productType* products;
    products = new productType[10];

    // Initialize products with names and prices
    products[0].set_product_name("iPhone 12");
    products[0].set_product_price(999.99);
    products[1].set_product_name("Galaxy S21");
    products[1].set_product_price(899.99);
    products[2].set_product_name("Ipad Pro");
    products[2].set_product_price(699.99);
    products[3].set_product_name(" Power Bank ");
    products[3].set_product_price(35.7);
    products[4].set_product_name("Charger USB type C ");
    products[4].set_product_price(15);
    products[5].set_product_name("Wireless headphones ");
    products[5].set_product_price(125.6);
    products[6].set_product_name("Wired headphones");
    products[6].set_product_price(10);
    products[7].set_product_name("cover");
    products[7].set_product_price(5.99);
    products[8].set_product_name("cover of Ipad");
    products[8].set_product_price(45.9);
    products[9].set_product_name("Usb flash drives");
    products[9].set_product_price(11);
    // ... Repeat for other products ...
    system("color 9");
    for (int i = 0; i < 10; i++) {
        section1.insert_product(products[i]);
    }
    section1.print_all_products();

    do {
        cout << "Enter your choice from 1 to " << 10 << " and 0 to exit: ";
        cin >> select_item;
        trolly.set_select_item(select_item);

        if (select_item > 0 && select_item <= 10) {
            cout << "Your choice is: " << products[select_item - 1].get_product_name() << "\n";
            cout << "Enter the quantity you want: ";
            cin >> quantity;

            trolly.add_item(products[select_item - 1]);
            trolly.set_product_quantity(products[select_item - 1], quantity);
            float total = products[select_item - 1].get_product_price() * products[select_item - 1].get_product_Quantity();

            cout << "The Product Name: " << products[select_item - 1].get_product_name();
            cout << "The product Cost: " << products[select_item - 1].get_product_price() << "\n";
            cout << "Number of Quantity: " << products[select_item - 1].get_product_Quantity() << endl;
            cout << "storge : " << products[select_item - 1].get_product_storge() << "\n";
            cout << "Total cost: $" << total << "\n";

            // Handle payment using the cashType class
            cashType cash;
            float money;
            cout << "Enter the amount of money: $";
            cin >> money;
            cash.set_accept_money(money);

            if (cash.is_valid(trolly, products[select_item - 1])) {
                cout << "Payment accepted. Remaining money: $" << cash.rest_of_money(trolly, products[select_item - 1]) << "\n";

                // Print the bill
                cash.print_bill(trolly, products);

                // Save the bill to a file
                fstream outfile;
                cash.print_bill_in_file(outfile, trolly, products);
                cout << "Bill saved to file 'BillFile.txt'.\n";
            }
            else {
                cout << "Insufficient funds. Please provide more money.\n";
            }
        }
        else if (select_item != 0) {
            cout << "Incorrect choice. Please choose a correct one.\n";
        }
    } while (select_item != 0);

    delete[] products; // Release allocated memory

    return 0;
}


