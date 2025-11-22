#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "dosen.h"
#include "mahasiswa.h"
#include "pelajaran.h"

using namespace std;

int main() {
    vector<user*> users;
    vector<pelajaran*> semuamapel;

    users.push_back(new dosen("Naser", "1234", "Naser Jawas, S.T., M.Kom., Ph.D"));
    users.push_back(new mahasiswa("dzaky", "1234", "Dzaky"));
    users.push_back(new mahasiswa("adrian", "4321", "Adrian"));
    users.push_back(new mahasiswa("yanuar", "5678", "Yanuar"));

    pelajaran* p1 = new pelajaran("Pemrograman Dasar", "Naser Jawas, S.T., M.Kom., Ph.D");
    p1->tambahmateri("Pengenalan OOP");
    semuamapel.push_back(p1);

    cout << "akademik classroom" << endl;

    string inuser, inpass;
    bool jalan = true;

    while(jalan) {
        cout << " Silahkan Login" << endl;
        cout << "Username : "; cin >> inuser;
        cout << "Password : "; cin >> inpass;

        user* currentuser = nullptr;

        for (user* u : users) {
            if (u->login(inuser, inpass)) {
                currentuser = u;
                break;
            }
        }

        if (currentuser != nullptr) {
            cout << "Login berhasil, selamat datang " << currentuser->getname() << endl;

            bool loginberhasil = true;
            while(loginberhasil) {
                currentuser->showmenu();
                cout << "Masukkan pilihan: ";
                int pilihan;
                cin >> pilihan;

        if (pilihan == 0) {
                    loginberhasil = false;
                    cout << "Kamu telah logout." << endl;
            }
            else {
                    dosen* d = dynamic_cast<dosen*>(currentuser);
                    mahasiswa* m = dynamic_cast<mahasiswa*>(currentuser);

        if (d != nullptr) {
                        
				if(pilihan == 1) {
                            cout << "Masukkan nama matkul: " << endl;
                            string nm;
                            cin.ignore(); getline(cin, nm);
                            
                            pelajaran* mapelbaru = new pelajaran(nm, d->getname());
                            semuamapel.push_back(mapelbaru);
                            d->createcourse(nm); 
                        }
                        else if(pilihan == 2) {
                            if(semuamapel.empty()) {
                                cout << "Belum ada matkul yang dibuat." << endl;
                            }
                            else {
                                cout << "Pilih matkul untuk diupload:" << endl;
                                for(int i=0; i < semuamapel.size(); i++) {
                                 cout << i+1 << ". " << semuamapel[i]->getnama() << endl;
                                }
                               		 cout << "Pilih nomor: ";
                                		int index;
                             cin >> index;
                                
                             if(index > 0 && index <= semuamapel.size()) {
                                   cout << "Isi konten dari materi: " << endl;
                                  string konten;
                                  cin.ignore(); getline(cin, konten);
                                    
                                    semuamapel[index-1]->tambahmateri(konten);
                                }
                                else {
                                    cout << "pilihan tidak ada." << endl;
                            }
                      }
                        }
                       else if(pilihan == 3) {
                            if(semuamapel.empty()) {
                                cout << "Belum ada matkul." << endl;
                            } else {
                                cout << "\nPilih matkul:" << endl;
                                for(int i=0; i < semuamapel.size(); i++) {
                                    cout << i+1 << ". " << semuamapel[i]->getnama() << endl;
                                }
                                cout << "Pilih nomor: ";
                                int index; cin >> index;
                                
                                if(index > 0 && index <= semuamapel.size()) {
                                    cout << "\nMateri di " << semuamapel[index-1]->getnama() << ":" << endl;
                                    semuamapel[index-1]->tampilmateri();
                                    
                                    cout << "\nNomor materi yang ingin dihapus: ";
                                    int nomorMateri; cin >> nomorMateri;
                                    semuamapel[index-1]->hapusmateri(nomorMateri);
                                } else {
                                    cout << "Pilihan tidak ada." << endl;
                                }
                            }
                        }
                
                
                 else if(pilihan == 4) {
                            if(semuamapel.empty()) {
                                cout << "Belum ada matkul untuk dihapus." << endl;
                            } else {
                                cout << "\nMateri kuliah yang tersedia:" << endl;
                                for(int i=0; i < semuamapel.size(); i++) {
                                    cout << i+1 << ". " << semuamapel[i]->getnama() << endl;
                                }
                                cout << "Pilih matkul untuk dihapus: ";
                                int index; cin >> index;
                                
                                if(index > 0 && index <= semuamapel.size()) {
                                    string namaMatKul = semuamapel[index-1]->getnama();
                                    
                                    cout << "apakah yakin " << namaMatKul << " ingin dihapus? (y/n): ";
                                    char konfirm; cin >> konfirm;
                                    
                                    if(konfirm == 'y' || konfirm == 'Y') {
                                        delete semuamapel[index-1];
                                        semuamapel.erase(semuamapel.begin() + index - 1);
                                        d->deletecourse(namaMatKul);
                                    } else {
                                        cout << "Pembatalan berhasil." << endl;
                                    }
                                } else {
                                    cout << "Pilihan tidak ada." << endl;
                                }
                		}
            }
                
                
                
                 else if (pilihan == 5) {
                            cout << "\nDaftar Mahasiswa: " << endl;
                            int no = 1;
                            for(user* u : users) {
                                if(dynamic_cast<mahasiswa*>(u)) {
                                    cout << no++ << ". " << u->getname() << endl;
                            }
                        }
                        }
                    }
                
 else if (m != nullptr) { 
                if (pilihan == 1) {
                          	cout << "Kelas yang tersedia: " << endl;
                          	  if(semuamapel.empty()) cout << "(Tidak ada kelas)" << endl;
                            
                            for(int i=0; i < semuamapel.size(); i++) {
                                cout << "- " << semuamapel[i]->getnama() << endl;
                            }
                        }
                        else if (pilihan == 2) {
                            if(semuamapel.empty()) {
                                cout << "Belum ada kelas dibuka." << endl;
                            } else {
                                cout << "\nPilih Kelas untuk Masuk:" << endl;
                                for(int i=0; i < semuamapel.size(); i++) {
                                    cout << i+1 << ". " << semuamapel[i]->getnama() << endl;
                                }
                                cout << "Pilih nomor: ";
                                int index; cin >> index;
                                
                                if(index > 0 && index <= semuamapel.size()) {
                                    	m->joinclass(semuamapel[index-1]->getnama());
                                    semuamapel[index-1]->tampilmateri();
                                } else {
                                    cout << "pilihan tidak ada." << endl;
                                }
                    }
            }
                  }
               }
            } 

        } 
        else {
            cout << "Username/Password salah, silahkan coba lagi." << endl;
        }

        cout << "\nMau login ulang? (y/n): ";
        char pilih; cin >> pilih;
        if(pilih == 'n') jalan = false;

    }
    
    
    return 0;
}