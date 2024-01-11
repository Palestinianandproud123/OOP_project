#pragma once
#include <iostream>
#include "Interface_productType.h"
using namespace std;
class productType {
    static int ProductID;
    string ProductName;
    float ProductPrice;
    int productID;
    int productQuantity;
    int ProductStorge = 100;

public:
    void set_product_name(const string& productName);
    string get_product_name() const;

    void set_product_price(float productPrice);
    float get_product_price() const;

    void set_product_Quantity(int);
    int get_product_Quantity() const;

    int get_product_id() const;
    int get_product_storge();

    bool isInStock() const;
    void decrementStorage();

    productType();

};

/*class QuantityType {
private: int quantity;
private: int selecter = 3;
private: productType  *products;
void set_product_quantity(productType& product, int quantity) {
    int index = selecter -1;
    if (index >= 0)
        productType&  selectedProduct; = products[index];
            if (quantity > 0 ) {
                this -> quantity = quantity;
            } else {
                this -> quantity = 1;
            }
    if (selectedProduct.get_product_id() == product.get_product_id()) {
              selectedProduct.set_product_Quantity(quantity);
              selectedProduct.get_product_storge() - selectedProduct.get_product_Quantity();
        }
*/
