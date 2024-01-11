#include <iostream>
#include <iomanip>
#include "Interface_PhoneSectionType.h"
#include "Interface_productType.h"
void PhoneSectionType::insert_product(const productType& product) {
    /*****************************************
    * to Enter the item/product
    *
    ******************************************/
    productType* newProductType = new productType[NumberOfProducts + 1];

    for (int i = 0; i < NumberOfProducts; i++) {
        newProductType[i] = products[i];
    }

    newProductType[NumberOfProducts] = product;

    delete[] products;
    products = newProductType;
    ++NumberOfProducts;
}
void PhoneSectionType::delete_product(int productID) {
    int productIndex = -1;
    /***********************************************************
     - Find the index of the product with the specified ID
     -To delete Item/product
    **************************************************************/
    for (int i = 0; i < NumberOfProducts; i++) {
        if (products[i].get_product_id() == productID) {
            productIndex = i;
            break;
        }
    }
    if (productIndex != -1) {
        productType* newProductType = new productType[NumberOfProducts - 1];
        for (int i = 0, j = 0; i < NumberOfProducts; i++) {
            if (i != productIndex) {
                newProductType[j++] = products[i];
            }
        }
        delete[] products;
        products = newProductType;
        NumberOfProducts--;
    }
    else {
        cout << "Product with ID " << productID << " not found. No product deleted." << endl;
    }
}
int PhoneSectionType::get_number_of_products() const {
    /**************************************
     To return number of Item/product
    ***************************************/
    return NumberOfProducts;
}
void PhoneSectionType::print_all_products() const {
    cout << setw(68) << setfill('*') << left
        << "*" << setfill(' ') << endl;
    cout << setw(25) << left << "Product ID" << " |" <<
        setw(25) << left << "Product Name" << " |"
        << setw(12) << left << "Product Price" << "|"
        << endl;
    cout << setw(68) << setfill('*') << left
        << "*" << setfill(' ') << endl;
    for (int i = 0; i < NumberOfProducts; i++) {
        if ((i + 1) < 10)
            cout << "0" << (i + 1) << " - ";
        else
            cout << (i + 1) << " - ";
        cout << setw(20) << left << products[i].get_product_id() << " |"
            << setw(25) << left << products[i].get_product_name() << " |"
            << setw(12) << left << products[i].get_product_price() << " |"
            << endl;
    }
    cout << setw(68) << setfill('*') << left << "*"
        << endl << endl;
}



