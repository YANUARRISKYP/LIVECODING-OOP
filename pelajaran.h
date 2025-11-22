#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class pelajaran {
    private:
    string namamatkul;
        string kodedosen;
        vector<string> daftarmateri;
        static int totalmatkul;
        
    public:
       
pelajaran(string nama, string dosen);
    void tambahmateri(string konten);
    void tampilmateri();
    string getnama()const;
    
    void hapusmateri(int index);
    int getjumlahmateri () const;
    
    static int gettotalmatkul(){
    	return totalmatkul;
	}
   

    
    pelajaran & operator+(const string&konten);
    bool operator==(const pelajaran& other )const;
};
#endif