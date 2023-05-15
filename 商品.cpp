#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class Product {
public:
    Product(string name, string EnglishName, double price, int stock, string unit, string EnglishUnit);
    string getName() const;
    string getEnglishName() const;
    double getPrice() const;
    int getStock() const;
    void setStock(int stock);
    string getUnit() const;
    string getEnglishUnit() const;
    int getUserChoice(int size);
    void displayMenu(bool isEnglish, const Product* products, int numProducts);
    void updateStock(int quantity);
private:
    string name;
    string englishName;
    double price;
    int stock;
    string unit;
    string EnglishUnit;
};
