#ifndef USER_H   
#define USER_H
#include <iostream>
#include <string>

using namespace std;

class user{
	protected:
	
	string username;
	string password;
	string namalengkap;
	
	public:
		user(string u,string p, string n);	
		virtual ~user(){
		}
	bool login (string u, string p);
	
	string getname ();
	
	virtual void showmenu() = 0;
};
#endif