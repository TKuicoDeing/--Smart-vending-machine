#ifndef Cost_H
#define Cost_H

class Cost {
private:
	int money; // �s�������B

public:
	Cost(); // �c�y���

	void addMoney(int inputMoney); // �K�[���B
	void getSpread(); // ��s�ÿ�X���A
	int returnAmount(); // ��^��e�l�B
};

#endif