	
	
	#include "user.h"
	#include "pelajaran.h"
	
	class dosen : public user{
		public:
		dosen (string u,string p, string n);	
		
		void showmenu() override;
		
		void createcourse(string namamatkul);
		void deletecourse(string namamatkul);
		
	};