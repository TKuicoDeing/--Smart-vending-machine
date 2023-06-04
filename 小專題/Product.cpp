#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(string name, string englishName, double price, int stock, string unit, string englishUnit) {
	this->name = name;
	this->englishName = englishName;
	this->price = price;
	this->stock = stock;
	this->unit = unit;
	this->EnglishUnit = englishUnit;
}

string Product::getName() const {
	return name;
}
string Product::getEnglishName() const {
	return englishName;
}

double Product::getPrice() const {
	return price;
}

int Product::getStock() const {
	return stock;
}

void Product::setStock(int stock) {
	this->stock = stock;
}

int Product::getUserChoice(int size) {
	int choice;
	cout << "選擇商品編號: ";
	cin >> choice;
	while (choice < 1 || choice > size) {
		cout << "無效的選擇。請重新輸入: ";
		cin >> choice;
	}
	return choice - 1;
}
void Product::displayMenu(bool isEnglish, const Product* products, int numProducts) {
	cout << (isEnglish ? "Product Menu:" : "商品選單:") << endl;
	for (int i = 0; i < numProducts; i++) {
		cout << i + 1 << ". " << (isEnglish ? products[i].getEnglishName() : products[i].getName()) << " $" << products[i].getPrice() << endl;
	}
}
void Product::updateStock(int quantity) {
	stock -= quantity;
}
string Product::getUnit() const {
	return unit;
}
string Product::getEnglishUnit()const {
	return EnglishUnit;
}
