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
			cout << endl << "�A���K�X�O =_=" << endl;
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
		cout << "��J�W�L15�Ӧr���I" << endl;
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
			cout << endl << "�٧A�٨S��J��" << endl;
		}
		else if (Acc.size() <= 20) {
			Cleanscreen();
			break;
		}
		else if (Acc.size() > 20) {
			cout << endl << "�o��ȤH�A�O���O���̦h20�r�� :)" << endl;
			cout << "�A���A�@�����| :)" << endl;
			getline(cin, play);
			setuserid(play);
			if (play.empty()) {
				cout << endl << "�ѥS���r��" << endl;
			}
			else if (play.size() <= 20) {
				Cleanscreen();
				break;
			}
			else if (play.size() > 20)
				cout << "�^�h���] :))";
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