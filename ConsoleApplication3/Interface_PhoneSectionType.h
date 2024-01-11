#pragma once

#include "Interface_productType.h"

class PhoneSectionType {
    productType* products;
    int NumberOfProducts = 0;
    productType PhoneProducts[10];

public:
    void insert_product(const productType& product);
    void delete_product(int productID);
    void print_all_products() const;
    int get_number_of_products() const;

    // public: PhoneSectionType(productType[10]);
   //  public: ~PhoneSectionType();
};

// insert product
// delete product
// get number of the products
// print all producs
