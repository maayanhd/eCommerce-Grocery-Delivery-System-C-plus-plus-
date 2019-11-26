#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include "Adress.h"
#include "ShoppingCart.h"

class Customer {

public:
	/* The idea of receiving the cityName etc and not the adress object is to avoid unenecessary calls of copy constructor,
	and overall it seems to me more logical */
	/*The constructor */
	Customer(const char* name, const char* password,const char* countryName, const char* cityName, const char* streetName, const int* house);
	Customer(const Customer&) = delete; // copy c'tor;
	~Customer();

public:
	bool setName(const char* name);
	void setPassword(const char* password);
	inline const char* getName() const { return this->name; };
	inline const char* getPassword() const { return this->password;};
	void print();
private:

	char* name;
	char * password;
	Adress adress;
	ShoppingCart sCart;
};



#endif