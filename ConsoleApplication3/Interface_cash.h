#include <iostream>
#include <fstream>
#include "Interface_TrollyType.h"
using  namespace std;
class cashType {
	float MoneyOnHand;
	TrollyType trolly; // Corrected the declaration
public:
	void set_accept_money(float);
	float get_accept_money() const;
	float Total(TrollyType trolly, productType) const;
	bool is_valid(TrollyType, productType) const; // Corrected the function name
	float rest_of_money(TrollyType, productType) const;
	void print_bill(TrollyType, productType[]) const;
	void print_bill_in_file(fstream&, TrollyType, productType[]) const;
};

