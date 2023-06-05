#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include"Account.h"
using namespace std;
Account::Account() {

}
Account::Account(string userid, char* password) {
	this->userid = userid;
	this->password = password;
}
void Account::setuserid(string userid) {
	this->userid = userid;
}
void Account::setpassword(char* password) {
	this->password = password;
}

string Account::getuserid() {
	return userid;
}
char* Account::getpassword() {
	return password;
}

int Account::getNumber() {
	return NUMBER;
}

void Account::hidepassword() {

	NUMBER = 30;
	const int ENTER = 13;
	char key;
	int countx = 0;
	char* word = new char[NUMBER];


	while ((key = _getch()) && countx < 16) {
		word[countx] = (char)key;
		if (key == 13 && countx == 0) {
			cout << endl << "你的密碼呢 =_=" << endl;
			exit(0);
		}
		if (key == '\b') {
			cout << '\b' << ' ' << '\b';
			if (countx - 1 > 0) { countx--; }
			else { countx = 0; }
		}
		else if (key >= '!' && key <= 'z') {
			cout << '*';
			countx++;
		}
		else if (key == 13)
			break;
	}
	cout << endl;
	if (countx >= 15) {
		cout << "輸入超過15個字元！" << endl;
		exit(0);
	}
	word[countx] = '\0';
	NUMBER = countx;
	password = word;
}
void Account::IDcheck() {
	string play, Acc = "";

	while (true) {
		getline(cin, Acc);
		setuserid(Acc);
		if (Acc.empty()) {
			cout << endl << "欸你還沒輸入阿" << endl;
		}
		else if (Acc.size() <= 20) {
			Cleanscreen();
			break;
		}
		else if (Acc.size() > 20) {
			cout << endl << "這位客人，是不是說最多20字元 :)" << endl;
			cout << "再給你一次機會 :)" << endl;
			getline(cin, play);
			setuserid(play);
			if (play.empty()) {
				cout << endl << "老兄打字阿" << endl;
			}
			else if (play.size() <= 20) {
				Cleanscreen();
				break;
			}
			else if (play.size() > 20)
				cout << "回去重設 :))";
		}
		exit(0);
	}
}

void Account::Cleanscreen() {
	system("cls");
}


void Account::Fluent() {
	this_thread::sleep_for(chrono::seconds(2));
	Cleanscreen();
}