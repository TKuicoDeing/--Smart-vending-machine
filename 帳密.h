#ifndef HI
#define HI
#include <string>
using namespace std;
class Account {
private:
	string userid;
	char* password;
public:
	Account();
	Account(string, char*);
	string success();
	string getuserid();
	char getpassword();
	void setuserid(string);
	void setpassword(char*);
	void hidepassword();
	void IDcheck();
	void Passwordcheck();
	void Cleanscreen();

};


#endif
