#include <iomanip>
#include "Interface_productType.h"

int productType::ProductID = 1000;

productType::productType() {
    ProductName = " ";
    ProductPrice = 0.0;
    productID = ProductID;
    ProductID++;
}

void productType::set_product_name(const string& productName) {
    /******************************************************************
     - to set the name of item
    *******************************************************************/
    this->ProductName = productName;
}

string productType::get_product_name() const {
    return ProductName;
}

void productType::set_product_price(float productPrice) {
    /******************************************************************
     - to set the price to item/product
    *******************************************************************/
    this->ProductPrice = productPrice;
}

float productType::get_product_price() const {
    return ProductPrice;
}

void productType::set_product_Quantity(int productQuantity) {
    /******************************************************************
     -to set the quantity of item/product
    *******************************************************************/
    this->productQuantity = productQuantity;
}

int productType::get_product_Quantity() const {
    return productQuantity;
}


int productType::get_product_id() const {
    return productID;
}

int productType::get_product_storge() {
    ProductStorge = ProductStorge - productQuantity;
    return ProductStorge;
    /**********
    * storge
    **********/
}

bool productType::isInStock() const {
    return (ProductStorge > 0);
}

void productType::decrementStorage() {
    ProductStorge--;
}