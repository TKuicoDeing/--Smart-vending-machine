#include "Cost.h"
#include <iostream>
#include <cstdlib> // �Ω�M���̹���system("cls")
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
	int a = money; // �O�s�i�J�ɪ����A
	int newMoney = 0;

	// �����s�ާ@�A�o��²��ܷN���N���B�M�s
	newMoney = money;
	money = 0;

	system("cls");
	cout << "�W�@�����B: " << a << endl;
	cout << "���: " << newMoney << endl;
}

int Cost::returnAmount() {
	return money;
}