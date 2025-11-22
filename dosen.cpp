#include "dosen.h"


dosen::dosen(string u, string p, string n) : user(u, p, n) {
}


void dosen::showmenu() {
    cout << "menu dosen:  " << namalengkap << endl;
    cout << "1. buat mata kuliah baru" << endl;
    cout << "2. upload materi" << endl;
    cout << "3. hapus materi dari matkul" << endl;
    cout << "4. hapus mata kuliah" << endl;
    cout << "5. lihat list mahasiswa" << endl;
    cout << "0. logout" << endl;
}

void dosen::createcourse(string namamatkul) {
    cout << "Course " << namamatkul << " telah dibuat" << endl;
}

void dosen :: deletecourse(string namamatkul){
	cout << "course "<< namamatkul << "telah dihapus" << endl;
}