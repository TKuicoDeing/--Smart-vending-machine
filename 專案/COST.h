#ifndef Cost_H
#define Cost_H

class Cost {
private:
	int money; // 存放投幣金額

public:
	Cost(); // 構造函數

	void addMoney(int inputMoney); // 添加金額
	void getSpread(); // 找零並輸出狀態
	int returnAmount(); // 返回當前餘額
};

#endif