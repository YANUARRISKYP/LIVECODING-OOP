#include "user.h"

using namespace std;

class mahasiswa : public user{
	
	public :
		
		mahasiswa(string u, string p, string n) ;
		~mahasiswa();
		
	void showmenu () override ;
	
	void joinclass (string kodekelas);
	
};