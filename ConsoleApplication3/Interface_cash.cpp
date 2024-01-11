#include "Interface_cash.h"
#include <fstream>
#include <iomanip>

void cashType::set_accept_money(float MoneyOnHand) {
    this->MoneyOnHand = MoneyOnHand;
}
float cashType::get_accept_money() const {
    return MoneyOnHand;
}
float cashType::Total(TrollyType trolly, productType product) const {
    float total = (trolly.get_product_quantity(product) * product.get_product_price());
    if (total > 3000) {
        total = total - (total - 0.02);
        return total;
    }
    else {
        return total;
    }
    return total;
}

bool cashType::is_valid(TrollyType trolly, productType product) const {
    float total = Total(trolly, product);
    if (total <= MoneyOnHand) {
        return true;
    }
    else {
        return false;
    }
}

float cashType::rest_of_money(TrollyType trolly, productType product) const {
    float total = Total(trolly, product);
    if (total > MoneyOnHand) {
        return MoneyOnHand - total;
    }
    return 0;
}
void cashType::print_bill(TrollyType troll, productType product[10]) const {
    cout << setfill(' ') << setw(25) << left << "Product ID "
        << setw(25) << left << "Product Name"
        << setw(25) << left << "Prodcuct Price"
        << setw(25) << left << "Product Quantity"
        << setw(25) << left << "Total cost for product"
        << endl;
    for (int i = 0; i < troll.get_number_of_order(); i++) {
        cout << setw(25) << left << product[troll.get_select_item()].get_product_id()
            << setw(25) << left << product[troll.get_select_item()].get_product_name()
            << setw(25) << left << product[troll.get_select_item()].get_product_price()
            << setw(25) << left << troll.get_product_quantity(product[10])
            << setw(25) << left << Total(troll, product[troll.get_select_item()])
            << endl;
    }
}
void cashType::print_bill_in_file(fstream& outfile, TrollyType trolly, productType product[10]) const {
    outfile.open("BillFile.txt");
    outfile << setw(25) << left << "Product ID "
        << setw(25) << left << "Product Name"
        << setw(25) << left << "Prodcuct Price"
        << setw(25) << left << "Product Quantity"
        << setw(25) << left << "Total cost for product"
        << endl;
    for (int i = 0; i < trolly.get_number_of_order(); i++) {
        outfile << setw(25) << left << product[trolly.get_select_item()].get_product_id()
            << setw(25) << left << product[trolly.get_select_item()].get_product_name()
            << setw(25) << left << product[trolly.get_select_item()].get_product_price()
            << setw(25) << left << trolly.get_product_quantity(product[10])
            << setw(25) << left << Total(trolly, product[trolly.get_select_item()])
            << endl;
    }
}
