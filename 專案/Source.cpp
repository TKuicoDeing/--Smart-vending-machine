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
	//創建帳號密碼
	Account account;
	cout << "創建少於等於20字元的帳號:";
	account.IDcheck();

	cout << "請創建少於等於15字元的密碼:";
	account.hidepassword();
	account.Cleanscreen();
	int a = account.getNumber();
	//確認密碼
	char* wd = account.getpassword();
	string s = "";

	for (int i = 0;i < a;i++)
		s += wd[i];

	string checkwd, doublecheck;
	cout << "現在我要確認你是" << account.getuserid() << "的擁有者" << endl;
	cout << "密碼-->";
	cin >> checkwd;
	if (checkwd == s)
		cout << "賣方忠告 : 買越多虧的越多" << endl;
	else if (checkwd != s) {

		cout << "我記得你5秒前設定過.." << endl;
		cout << "重新輸一次吧(請稍等)" << endl;
		account.Fluent();
		cin >> doublecheck;
		if (doublecheck == s) {
			cout << "希望下次見到你，你的記憶力能超越金魚" << endl;
		}
		else if (doublecheck != s) {
			cout << "欸老哥..拜託一下" << endl;
			exit(0);
		}

	}
	account.Fluent();

	bool isEnglish = false; // 初始語言為中文

	// 創建商品陣列
	Product products[] = {
		Product("運動飲料", " Energy Drink", 25, 10,"瓶","bottles of"),
		Product("牛奶", " Milk", 45, 10,"瓶","bottles of"),
		Product("可樂", " Cola", 25, 10,"罐","cans of"),
		Product("紅茶", " Black Tea", 20, 10,"瓶","bottlse of"),
		Product("雪碧", " Sprite", 25, 10,"罐","cans of"),
		Product("薯片", " Chips", 35, 10,"包","packets of"),
		Product("巧克力"," Chocolate",39,10,"片","pieces of"),
		Product("點心麵"," Noodle Snack",30,10,"包","packets of"),
		Product("口香糖"," Chewing Gum",40,10,"包","packets of"),
		Product("泡麵","Instant Noodle",30,10,"碗","bowls of"),
	};

	int numProducts = sizeof(products) / sizeof(products[0]);// 計算商品陣列的大小

	// 語言選擇
	int languageChoice;
	cout << "Select language (選擇語言):" << endl;
	cout << "1. English" << endl;
	cout << "2. 中文" << endl;
	cout << "Choice (選擇): ";
	cin >> languageChoice;
	account.Fluent();

	while (languageChoice != 1 && languageChoice != 2) {
		cout << "Invalid choice. Please re-enter: ";
		cin >> languageChoice;
	}

	isEnglish = (languageChoice == 1);

	char continueChoice = 'Y'; // 初始化繼續購買的選擇為 'Y'

	while (continueChoice == 'Y' || continueChoice == 'y') {

		// 顯示商品選單
		products[0].displayMenu(isEnglish, products, numProducts);

		// 選擇商品
		int choiceIndex = getUserChoice(numProducts, isEnglish);
		string choice = products[choiceIndex].getName();

		// 顯示商品庫存
		int stock = products[choiceIndex].getStock();
		cout << (isEnglish ? "Inventory: " : "商品庫存: ") << stock << endl;

		// 輸入購買數量
		int quantity, Tquantity = 11;
		cout << (isEnglish ? "Purchase quantity:" : "購買數量: ");
		cin >> quantity;

		double totalPrice = products[choiceIndex].getPrice() * quantity;
		int T = 0;
		// 檢查庫存
		if (quantity > stock || quantity == 0) {
			T++;
			cout << (isEnglish ? "Inventory shortage.Please select a different quantity for the item. " : "庫存不足，請重新選擇商品數量!") << endl;
			this_thread::sleep_for(chrono::seconds(1));
			while (Tquantity > stock) {
				cout << (isEnglish ? "Please enter again ! : " : "請重輸一次: ") << endl;
				account.Fluent();
				cin >> Tquantity;
				if (Tquantity > stock || Tquantity == 0)
					cout << (isEnglish ? "not enough= = : " : "就不夠吼= =") << endl;
			}
			totalPrice = products[choiceIndex].getPrice() * Tquantity;
			string productName = isEnglish ? products[choiceIndex].getEnglishName() : products[choiceIndex].getName();
			string productUnit = products[choiceIndex].getUnit(); // 取得單位
			cout << (isEnglish ? "You have purchased " : "您購買了 ") << Tquantity << " " << (isEnglish ? products[choiceIndex].getEnglishUnit() : productUnit) << productName
				<< "，" << (isEnglish ? "The total cost was " : "總共消費 ") << totalPrice << " " << (isEnglish ? "dollars" : "元") << endl;
		}
		else if (quantity < stock || Tquantity < stock) {
			// 計算總價格、顯示購買明細

			string productName = isEnglish ? products[choiceIndex].getEnglishName() : products[choiceIndex].getName();
			string productUnit = products[choiceIndex].getUnit(); // 取得單位
			cout << (isEnglish ? "You have purchased " : "您購買了 ") << quantity << " " << (isEnglish ? products[choiceIndex].getEnglishUnit() : productUnit) << " " << productName
				<< "，" << (isEnglish ? "The total cost was " : "總共消費 ") << totalPrice << " " << (isEnglish ? "dollars" : "元") << endl;

		}

		//付錢
		int customerPayment = 0;
		Cost cost;

		while (customerPayment < totalPrice) {
			int money;
			cout << "投幣: ";
			cin >> money;

			if (money <= 0) {
				cout << "請重新投幣" << endl;
				continue;
			}

			customerPayment += money;
			cout << "已投入金額: " << customerPayment << endl;
		}

		int change = customerPayment - totalPrice;
		if (change > 0) {
			cout << "Change: " << change << endl;
			cost.addMoney(change);
		}

		cost.getSpread();

		// 更新商品庫存
		if (T > 0)
			products[choiceIndex].updateStock(Tquantity);
		else
			products[choiceIndex].updateStock(quantity);

		// 更新庫存量並顯示商品購買明細
		if (T > 0)
			products[choiceIndex].setStock(stock - Tquantity);
		else
			products[choiceIndex].setStock(stock - quantity);
		cout << (isEnglish ? "The remaining quantity of the product: " : "商品剩餘: ") << products[choiceIndex].getStock() << endl;

		// 詢問是否繼續購買
		cout << (isEnglish ? "Would you like to continue shopping？(Y/N): " : "是否要繼續購買？(Y/N): ");
		cin >> continueChoice;
		account.Fluent();
	}

	cout << (isEnglish ? "Thank you for your visit! You're welcome to come again next time." : "感謝您的光臨，歡迎下次再來!") << endl;

	return 0;
}

int getUserChoice(int size, bool isEnglish) {
	int choice;
	cout << (isEnglish ? "Select product number: " : "選擇商品編號: ");
	cin >> choice;
	while (choice < 1 || choice > size) {
		cout << (isEnglish ? "Invalid choice. Please re-enter: " : "無效的選擇。請重新輸入: ");
		cin >> choice;
	}
	return choice - 1; // 將索引轉換為陣列索引
}
