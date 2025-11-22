#include "mahasiswa.h"


mahasiswa::mahasiswa(string u, string p, string n):user(u, p, n){
}

mahasiswa::~mahasiswa(){
	
}
void mahasiswa::showmenu(){
    cout << "dashboard mahasiswa: " <<namalengkap << endl;
	cout << "1. lihat daftar mata kuliah" << endl;
cout << "2. gabung kelas" << endl;
    cout << "0. logout " << endl;
}


void mahasiswa::joinclass(string kodekelas){
    cout <<"Berhasil gabung kelas: "<< kodekelas << endl;
}