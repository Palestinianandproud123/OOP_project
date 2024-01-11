#pragma once
#include "Interface_PhoneSectionType.h"
#include <iostream>
using namespace std;
class TrollyType {
    int selecter;
    int NumberOfOrder;
    productType* products;
    //    private: int *productQuantity;

public:
    void set_select_item(int selecter);
    int get_select_item() const;

    void add_item(const productType&) const;

    void set_product_quantity(productType&, int) const;
    int get_product_quantity(productType&) const;

    int get_number_of_order() const;
    bool is_enable(const productType& product, int choice_select) const;
    void print_trolly() const;

    // public: float Total(productType products[]); // need to fix 
     //public: int make_sale(productType products[], int);
     // if you want to make array of trolly make default constrcuter
};



