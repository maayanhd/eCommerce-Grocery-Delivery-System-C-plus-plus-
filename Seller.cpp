#include "Seller.h"

Seller::Seller(const string& userName, const string& password,Address a) : User(userName, password, a) ,feedbacks(NULL) {
}
Seller:: ~Seller()
{
	int size = availableProducts.getSize();
	// Releasing each and every pointer to product 
	for (int i = 0; i < size; ++i)
		delete availableProducts[i];

}

Seller::Seller(const Seller& other) :User(other)
{
	this->availableProducts = other.availableProducts;
	this->feedbacks = other.feedbacks;
}
Seller::Seller(Seller&& other) : User( move(other) )
{
	this->availableProducts = other.availableProducts;
	this->feedbacks = other.feedbacks;
}

bool Seller::ProductExists(const string& nameOfProduct) const
{
	bool exists = false;
	int numOfProducts = availableProducts.getSize();
	for (int i = 0; i < numOfProducts && !exists; ++i)
	{
		if (nameOfProduct.compare(availableProducts[i]->getName()) == 0)
		{
			exists = true;								// Product is already exists
			cout << "A product with an identical name already exists in the seller's available products list\n";
		}
	}
	return exists;
}

void Seller::addProduct(string& prodName, float price, Category ctg)
{
	Product * newProduct = new Product(prodName, price, ctg, *this);
	availableProducts += newProduct;
	cout << "Product Added successfully to the seller:\n";
	cout << *this;										    // Printing the seller's details
}

bool Seller::optionIsValid(int option) const
{
	return (option >= 1 && option <= 4);
}
bool Seller::priceIsValid(float price) const
{
	return price > 0.0;										// a Price of a product must be positive number 
}

void Seller::toOs(ostream& os) const
{
	int numOfProducts = availableProducts.getSize();
	os << "My Available Products\n";
	for (int i = 0; i < numOfProducts; ++i)
	{
		os << i << ". " << *(availableProducts[i]) << endl; // Using operator << in product class
	}
}




