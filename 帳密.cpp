#include <iostream>
#include <string>
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
char Account::getpassword() {
	return *password;
}

void Account::hidepassword() {

	const int NUMBER = 30;
	const int ENTER = 13;
	char key;
	char passwd[NUMBER];
	int countx = 0;

	while ((key = _getch()) != ENTER && countx < 20) {
		passwd[countx] = (char)key;
		if (key == '\b') {
			cout << '\b' << ' ' << '\b';
			if (countx - 1 > 0) { countx--; }
			else { countx = 0; }
		}
		else if (key >= '!' && key <= 'z') {
			cout << '*';
			countx++;
		}
	}
	cout << endl;
	if (countx >= 20) {
		cout << "輸入超過20個字元！" << endl;
	}
	passwd[countx] = '\0';
	password = passwd;
}
void Account::IDcheck() {
	string play, Acc = "";

	while (true) {
		getline(cin, Acc);
		setuserid(Acc);
		if (Acc.size() < 20 || Acc.empty()) {
			Cleanscreen();
			break;
		}
		else if (Acc.size() > 20) {
			cout << endl << "這位客人，是不是說最多20字元 :)" << endl;
			getline(cin, play);
			if (play.size() >= 1 || play.empty())
				cout << "回去重設 :))";
		}
		exit(0);
	}
}

void Account::Cleanscreen() {
	system("cls");
}
