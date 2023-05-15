#include "COST.h"
#include <iostream>

COST::COST(int price) {
    totalCoins = 0;
    productPrice = price;
}

void COST::insertCoin(int coin) {
    totalCoins += coin;
}

void COST::purchaseProduct() {
    if (totalCoins >= productPrice) {
        int change = totalCoins - productPrice;
        std::cout << "購買成功！" << std::endl;
        if (change > 0) {
            std::cout << "找零：" << change << "元" << std::endl;
        }
        totalCoins = 0;
    } else {
        std::cout << "投入金額不足，請投入更多硬幣" << std::endl;
    }
}

int COST::getSpread() const {
    return totalCoins - productPrice;
}

int COST::returnAmount() {
    int change = totalCoins;
    totalCoins = 0;
    return change;
}
