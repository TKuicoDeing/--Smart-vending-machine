#ifndef HI
#define HI
#include <string>
using namespace std;
class Account {
private:
	int NUMBER;
	string userid;
	char* password;
public:
	Account();
	Account(string, char*);
	int getNumber();
	string getuserid();
	char* getpassword();
	void setuserid(string);
	void setpassword(char*);
	void hidepassword();
	void IDcheck();
	void Cleanscreen();
	void Fluent();

};


#endif
