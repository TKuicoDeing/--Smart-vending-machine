#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>
#include "Account.h"
#include "Product.h"
#include "COST.h"
using namespace std;

int getUserChoice(int, bool);

int main() {
	//�Ыرb���K�X
	Account account;
	cout << "�Ыؤ֩󵥩�20�r�����b��:";
	account.IDcheck();

	cout << "�гЫؤ֩󵥩�15�r�����K�X:";
	account.hidepassword();
	account.Cleanscreen();
	int a = account.getNumber();
	//�T�{�K�X
	char* wd = account.getpassword();
	string s = "";

	for (int i = 0;i < a;i++)
		s += wd[i];

	string checkwd, doublecheck;
	cout << "�{�b�ڭn�T�{�A�O" << account.getuserid() << "���֦���" << endl;
	cout << "�K�X-->";
	cin >> checkwd;
	if (checkwd == s)
		cout << "��詾�i : �R�V�h�����V�h" << endl;
	else if (checkwd != s) {

		cout << "�ڰO�o�A5��e�]�w�L.." << endl;
		cout << "���s��@���a(�еy��)" << endl;
		account.Fluent();
		cin >> doublecheck;
		if (doublecheck == s) {
			cout << "�Ʊ�U������A�A�A���O�ФO��W�V����" << endl;
		}
		else if (doublecheck != s) {
			cout << "�٦ѭ�..���U�@�U" << endl;
			exit(0);
		}

	}
	account.Fluent();

	bool isEnglish = false; // ��l�y��������

	// �Ыذӫ~�}�C
	Product products[] = {
		Product("�B�ʶ���", " Energy Drink", 25, 10,"�~","bottles of"),
		Product("����", " Milk", 45, 10,"�~","bottles of"),
		Product("�i��", " Cola", 25, 10,"��","cans of"),
		Product("����", " Black Tea", 20, 10,"�~","bottlse of"),
		Product("����", " Sprite", 25, 10,"��","cans of"),
		Product("����", " Chips", 35, 10,"�]","packets of"),
		Product("���J�O"," Chocolate",39,10,"��","pieces of"),
		Product("�I����"," Noodle Snack",30,10,"�]","packets of"),
		Product("�f���}"," Chewing Gum",40,10,"�]","packets of"),
		Product("�w��","Instant Noodle",30,10,"�J","bowls of"),
	};

	int numProducts = sizeof(products) / sizeof(products[0]);// �p��ӫ~�}�C���j�p

	// �y�����
	int languageChoice;
	cout << "Select language (��ܻy��):" << endl;
	cout << "1. English" << endl;
	cout << "2. ����" << endl;
	cout << "Choice (���): ";
	cin >> languageChoice;
	account.Fluent();

	while (languageChoice != 1 && languageChoice != 2) {
		cout << "Invalid choice. Please re-enter: ";
		cin >> languageChoice;
	}

	isEnglish = (languageChoice == 1);

	char continueChoice = 'Y'; // ��l���~���ʶR����ܬ� 'Y'

	while (continueChoice == 'Y' || continueChoice == 'y') {

		// ��ܰӫ~���
		products[0].displayMenu(isEnglish, products, numProducts);

		// ��ܰӫ~
		int choiceIndex = getUserChoice(numProducts, isEnglish);
		string choice = products[choiceIndex].getName();

		// ��ܰӫ~�w�s
		int stock = products[choiceIndex].getStock();
		cout << (isEnglish ? "Inventory: " : "�ӫ~�w�s: ") << stock << endl;

		// ��J�ʶR�ƶq
		int quantity, Tquantity = 11;
		cout << (isEnglish ? "Purchase quantity:" : "�ʶR�ƶq: ");
		cin >> quantity;

		double totalPrice = products[choiceIndex].getPrice() * quantity;
		int T = 0;
		// �ˬd�w�s
		if (quantity > stock || quantity == 0) {
			T++;
			cout << (isEnglish ? "Inventory shortage.Please select a different quantity for the item. " : "�w�s�����A�Э��s��ܰӫ~�ƶq!") << endl;
			this_thread::sleep_for(chrono::seconds(1));
			while (Tquantity > stock) {
				cout << (isEnglish ? "Please enter again ! : " : "�Э���@��: ") << endl;
				account.Fluent();
				cin >> Tquantity;
				if (Tquantity > stock || Tquantity == 0)
					cout << (isEnglish ? "not enough= = : " : "�N�����q= =") << endl;
			}
			totalPrice = products[choiceIndex].getPrice() * Tquantity;
			string productName = isEnglish ? products[choiceIndex].getEnglishName() : products[choiceIndex].getName();
			string productUnit = products[choiceIndex].getUnit(); // ���o���
			cout << (isEnglish ? "You have purchased " : "�z�ʶR�F ") << Tquantity << " " << (isEnglish ? products[choiceIndex].getEnglishUnit() : productUnit) << productName
				<< "�A" << (isEnglish ? "The total cost was " : "�`�@���O ") << totalPrice << " " << (isEnglish ? "dollars" : "��") << endl;
		}
		else if (quantity < stock || Tquantity < stock) {
			// �p���`����B����ʶR����

			string productName = isEnglish ? products[choiceIndex].getEnglishName() : products[choiceIndex].getName();
			string productUnit = products[choiceIndex].getUnit(); // ���o���
			cout << (isEnglish ? "You have purchased " : "�z�ʶR�F ") << quantity << " " << (isEnglish ? products[choiceIndex].getEnglishUnit() : productUnit) << " " << productName
				<< "�A" << (isEnglish ? "The total cost was " : "�`�@���O ") << totalPrice << " " << (isEnglish ? "dollars" : "��") << endl;

		}

		//�I��
		int customerPayment = 0;
		Cost cost;

		while (customerPayment < totalPrice) {
			int money;
			cout << "���: ";
			cin >> money;

			if (money <= 0) {
				cout << "�Э��s���" << endl;
				continue;
			}

			customerPayment += money;
			cout << "�w��J���B: " << customerPayment << endl;
		}

		int change = customerPayment - totalPrice;
		if (change > 0) {
			cout << "Change: " << change << endl;
			cost.addMoney(change);
		}

		cost.getSpread();

		// ��s�ӫ~�w�s
		if (T > 0)
			products[choiceIndex].updateStock(Tquantity);
		else
			products[choiceIndex].updateStock(quantity);

		// ��s�w�s�q����ܰӫ~�ʶR����
		if (T > 0)
			products[choiceIndex].setStock(stock - Tquantity);
		else
			products[choiceIndex].setStock(stock - quantity);
		cout << (isEnglish ? "The remaining quantity of the product: " : "�ӫ~�Ѿl: ") << products[choiceIndex].getStock() << endl;

		// �߰ݬO�_�~���ʶR
		cout << (isEnglish ? "Would you like to continue shopping�H(Y/N): " : "�O�_�n�~���ʶR�H(Y/N): ");
		cin >> continueChoice;
		account.Fluent();
	}

	cout << (isEnglish ? "Thank you for your visit! You're welcome to come again next time." : "�P�±z�����{�A�w��U���A��!") << endl;

	return 0;
}

int getUserChoice(int size, bool isEnglish) {
	int choice;
	cout << (isEnglish ? "Select product number: " : "��ܰӫ~�s��: ");
	cin >> choice;
	while (choice < 1 || choice > size) {
		cout << (isEnglish ? "Invalid choice. Please re-enter: " : "�L�Ī���ܡC�Э��s��J: ");
		cin >> choice;
	}
	return choice - 1; // �N�����ഫ���}�C����
}
