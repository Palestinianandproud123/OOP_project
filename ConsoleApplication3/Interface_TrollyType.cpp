#include "Interface_TrollyType.h"
#include <iomanip>
#include "Interface_productType.h"
/*
bool TrollyType::is_enable(const productType& product, int choice_select) const {
    int index = choice_select - 1; // Adjust for 0-based indexing
    if (index >= 0 && index < NumberOfOrder) {
        const productType& selectedProduct = products[index];
        return (selectedProduct.isInStock() && (selectedProduct.get_product_Quantity() > 0));
    } else {
        cout << "Invalid product selection.\n";
        return false;
    }
}*/


void TrollyType::set_select_item(int selecter) {
    if (selecter > 0) {
        this->selecter = selecter;
        NumberOfOrder++;
    }
}

int TrollyType::get_select_item() const {
    return selecter;
}

int TrollyType::get_number_of_order() const {
    return NumberOfOrder;
}

bool TrollyType::is_enable(const productType& product, int choice_select) const {
    int index = choice_select - 1; // Adjust for 0-based indexing

    if (index >= 0 && index < NumberOfOrder) {
        productType& selectedProduct = products[index];

        return (selectedProduct.isInStock() && (selectedProduct.get_product_Quantity() > 0));
    }
    else {
        cout << "Invalid product selection.\n";
        return false;
    }
}

void TrollyType::add_item(const productType& product) const {
    /******************************************************************

    ******************************************************************/
    int index = selecter - 1;

    if (index >= 0 && index < NumberOfOrder) {
        productType& selectedProduct = products[index];
        cout << "Item added to the trolley: " << selectedProduct.get_product_name();
    }
    else {
        cout << "Invalid product selection.\n";
    }
}

/*void TrollyType::add_item(productType& product, int productQuantity) {
    int index = selecter - 1;
    if (index >= 0 && index < NumberOfOrder) {
        productType& selectedProduct = products[index];
        if (is_enable(selectedProduct, selecter)) {
            // Check if the requested quantity is available
            if (productQuantity > 0 && productQuantity <= selectedProduct.get_product_Quantity()) {
                // Allocate memory for productQuantities if not already done
                if (!this->productQuantity) {
                    this->productQuantity = new int[get_number_of_order()];
                }
                this->productQuantity[index] = productQuantity;
                // Set quantity in the product
                selectedProduct.set_product_Quantity(productQuantity);
                //selectedProduct.product_Quantity() =  product->get_product_Quantity() + productQuantity;

                // Update the quantity in the trolly1 object
                //trolly1.set_product_quantity(selectedProduct, productQuantity);
                cout << "Item added to the trolley: " << selectedProduct.get_product_name()
                          << " (Quantity: " << productQuantity << ")\n";
            } else {
                cout << "Invalid quantity. Please choose a quantity between 1 and "
                          << selectedProduct.get_product_Quantity() << ".\n";
            }
        } else {
           cout << "Cannot add the item to the trolley. Product is out of stock or invalid quantity.\n";
        }
    } else {
       cout << "Invalid product selection.\n";
    }
}
*/

void TrollyType::print_trolly() const {

    cout << setw(125) << left << setfill('*') << "*" << "\n" << setfill(' ');
    cout << setw(62.5) << right << "Trolley Contents " << setw(62.5) << left << "\n";

    for (int i = 0; i < NumberOfOrder; i++) {
        const productType& product = products[i];
        //int quantity = productQuantity[i]; // Access quantity from the array
        float totalPrice = product.get_product_price() * product.get_product_Quantity();

        cout << setw(25) << left << "Product ID"
            << setw(25) << left << "Product Name"
            << setw(25) << left << "Product Price"
            << setw(25) << left << "Product Qunatity"
            << setw(25) << left << "Product Total"
            << endl;

        cout << setw(25) << left << product.get_product_id()
            << setw(25) << left << product.get_product_name()
            << setw(25) << left << product.get_product_price()
            << setw(25) << left << product.get_product_Quantity()
            << setw(25) << left << fixed << setprecision(2) << totalPrice
            << endl;
    }
}
void TrollyType::set_product_quantity(productType& product, int quantity) const {
    product.set_product_Quantity(quantity);

}
int TrollyType::get_product_quantity(productType& product) const {
    return product.get_product_Quantity();
}

