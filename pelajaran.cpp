#include "pelajaran.h"

int pelajaran :: totalmatkul = 0;

pelajaran::pelajaran(string nama, string dosen) : namamatkul(nama), kodedosen(dosen) {
    totalmatkul++;  
    cout << "Matkul '" << nama << "' berhasil dibuat. Total matkul: " << totalmatkul << endl;
}

pelajaran& pelajaran::operator+(const string& konten){
	daftarmateri.push_back(konten);
	cout << "materi sudah diupload"<< endl;
	return *this;
}

bool pelajaran::operator==(const pelajaran &other )const {
	return(namamatkul== other.namamatkul && kodedosen==other.kodedosen);
}

void pelajaran::tambahmateri(string konten) {
    daftarmateri.push_back(konten);
    cout << "materi sudah diupload" << endl;
}

void pelajaran::tampilmateri() {
    cout << "materi kuliah " << namamatkul << ":" << endl;
    if(daftarmateri.empty()) {
        cout << "(Belum ada materi)" << endl;
    } else {
        for(int i = 0; i < daftarmateri.size(); i++) {
            cout << i+1 << ". " << daftarmateri[i] << endl;
        }
    }
}

void pelajaran :: hapusmateri(int index){
	if (index>0 && index <=daftarmateri.size()){
		cout << "materi '" << daftarmateri[index-1]<< "' berhasil dihapus" << endl;
		daftarmateri.erase(daftarmateri.begin()+ index - 1);
	} else{
		cout << "materi tidak ditemukan" << endl;
	}
}

int pelajaran::getjumlahmateri() const{
	return daftarmateri.size();
}

string pelajaran::getnama() const {
    return namamatkul;
}