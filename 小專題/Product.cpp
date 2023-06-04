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
	cout << "��ܰӫ~�s��: ";
	cin >> choice;
	while (choice < 1 || choice > size) {
		cout << "�L�Ī���ܡC�Э��s��J: ";
		cin >> choice;
	}
	return choice - 1; // �N�����ഫ���}�C����
}
void Product::displayMenu(bool isEnglish, const Product* products, int numProducts) {
	cout << (isEnglish ? "Product Menu:" : "�ӫ~���:") << endl;
	for (int i = 0; i < numProducts; i++) {
		if (i == 9) {
			cout << i + 1 << "| " << (isEnglish ? products[i].getEnglishName() : products[i].getName()) << " $" << products[i].getPrice() << endl;
			break;
		}
		cout << i + 1 << " | " << (isEnglish ? products[i].getEnglishName() : products[i].getName()) << " $" << products[i].getPrice() << endl;

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