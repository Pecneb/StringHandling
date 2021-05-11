#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;


void szoveg_noveles(string *szoveg, int &meret) {
    string *tmp_szoveg = new string[meret+2];
    for(int i; i<meret; i++) {
        tmp_szoveg[i] = szoveg[i];
    }
    delete[] szoveg;
    szoveg = tmp_szoveg;
    delete[] tmp_szoveg;
    meret = meret+2;
}


int main(int argc, char **argv) {
    int szovegmeret = 2;
    string *szoveg = new string[szovegmeret];
    int szocount = 0;
    string buff;
    do {
        getline(cin, buff, ' ');
        if(buff != "[vege]") {
            szoveg[szocount] = buff;
            szocount++;
            if(szocount == szovegmeret) {
                szoveg_noveles(szoveg, szovegmeret);
            }
        }
    } while(buff != "vege");
    for(int i; i<szocount; i++) {
        cout << szoveg[i] << '\t';
    }
    return 0;
}