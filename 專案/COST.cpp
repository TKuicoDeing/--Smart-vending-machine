#include "Cost.h"
#include <iostream>
#include <cstdlib> // 用於清除屏幕的system("cls")
using namespace std;

Cost::Cost() {
	money = 0;
}

void Cost::addMoney(int inputMoney) {
	money += inputMoney;
	system("cls");
	cout << "Money: " << money << endl;
}

void Cost::getSpread() {
	int a = money; // 保存進入時的狀態
	int newMoney = 0;

	// 執行找零操作，這裡簡單示意為將金額清零
	newMoney = money;
	money = 0;

	system("cls");
	cout << "上一筆金額: " << a << endl;
	cout << "找錢: " << newMoney << endl;
}

int Cost::returnAmount() {
	return money;
}