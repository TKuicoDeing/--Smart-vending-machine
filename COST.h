// COST.h
#ifndef COST_H
#define COST_H

class COST {
private:
    int totalCoins;
    int productPrice;

public:
    COST(int price);
    void insertCoin(int coin);
    void purchaseProduct();
    int getSpread() const;
    int returnAmount();
};

#endif
