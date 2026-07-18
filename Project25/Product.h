#pragma once

enum ProductType
{
	NONE, BAKERY, DAIRY, CONFECTIONERS, BEVEREAGES
};

class Product
{
private:
	size_t id = ++counter;
	char* name = nullptr;
	size_t price = 0;
	size_t quantity = 0;
	ProductType productType = ProductType::NONE;
	static size_t counter;
public:
	static const size_t MAX_QUANTITY = 1000;
	Product() = default;
	Product(const char* name);
	Product(const char* name, const size_t& price, const size_t& quantity = 0, ProductType productType = ProductType::NONE);
	Product(const Product& other);
	void operator=(const Product& right);
	~Product();

	void setName(const char* name);
	void setPrice(const size_t price);
	void setQuantity(const size_t quantity);
	void setProductType(const ProductType& productType);

	void print() const;
	static size_t getCounter(); // static method linked not with obj linked with class dont get this

	static bool sameTypeProduct(const Product& one, const Product& two);
};

inline size_t Product::getCounter()
{
	return counter;
}

inline bool Product::sameTypeProduct(const Product& one, const Product& two)
{
	return one.productType == two.productType;
}



