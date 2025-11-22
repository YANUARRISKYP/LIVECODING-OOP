#include "user.h"


user::user(string u, string p, string n) : username(u), password(p), namalengkap(n) {
}


bool user::login(string u, string p) {
    return (u == username && p == password);
}


string user::getname() {
    return namalengkap;
}