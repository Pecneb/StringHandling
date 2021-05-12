#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

struct Stat {
    string szo;
    int szocount;
    double szazalek;
    int csikhossz;
};

void gyakorisag(Stat &szo, int osszes) {
    szo.szazalek = double(szo.szocount)/osszes;
}

void bsort(Stat *szavak, int meret) {
    for(int i=0; i<(meret-1); i++) {
        for(int j=0; j< (meret - (i-1)); j++) {
            if(szavak[j].szocount > szavak[j+1].szocount) {
                Stat cs = szavak[j];
                szavak[j] = szavak[j+1];
                szavak[j+1] = cs;
            }
        }
    }
}

void csikhossz_szamitas(Stat *szavak, int szavakmeret){
    int maxcsikhossz = 20;
    int maxszocount = szavak[0].szocount;
    for(int i=0; i<szavakmeret; i++) {
        szavak[i].csikhossz = maxcsikhossz*(szavak[i].szocount/maxszocount);
    }
}

string* szovegnovel(string *szoveg, int &meret) {
    string *tmp_szoveg = new string[meret+1];
    for(int i=0; i<meret; i++) {
    tmp_szoveg[i] = szoveg[i];
    }
    meret = meret+1;
    delete [] szoveg;
    return tmp_szoveg;
}

int Tartalmaz(Stat *szavak, string szo, const int meret) {
   int i=0;
   while(i<meret && szavak[i].szo != szo) {
       i++;
   }
   if(i<meret) {
       return i;
   }
   return 0;
}

void StatHozzaad(Stat *szavak, string szo, int szavakszama, int szavakmeret) {
    szavakmeret++;
    Stat *tmp = new Stat[szavakmeret];
    for(int i=0; i<szavakszama; i++) {
        tmp[i] = szavak[i];
    }
    szavakszama++;
    tmp[szavakszama].szo = szo;
    tmp[szavakszama].szocount = 1;
    delete[] szavak;
    szavak = tmp;
}

Stat* Elemzes(string *szoveg, const int szovegmeret) {
    int szavakszama = 0;
    int statmeret = 1;
    Stat *szavak = new Stat[statmeret];
    for(int i=0; i<szovegmeret; i++) {
        int tart = Tartalmaz(szavak, szoveg[i], szavakszama);
        if(tart == 0) {
            StatHozzaad(szavak, szoveg[i], szavakszama, statmeret);
        } else {
            szavak[tart].szocount++;
        }
    }
    bsort(szavak, szavakszama);
    for(int i=0; i<szavakszama; i++) {
        gyakorisag(szavak[i], szovegmeret);
        
    }
    return szavak;
}

void PrintStat(Stat *szavak) {
    for(int i=0; i<10; i++) {
        for(int j=0; j<szavak[i].csikhossz; j++) {
            cout << '*';
        }
        cout << ' ' << szavak[i].szo << ' ' << szavak[i].szocount << ' ' << szavak[i].szazalek << "%\n";
    }
}

int main(int argc, char **argv) {
    int szovegmeret = 1;
    string *szoveg = new string[szovegmeret];
    int szocount = 0;
    string buff;
    while(cin >> buff , buff != "[vege]") {
        if(szocount == szovegmeret) {
            szoveg = szovegnovel(szoveg, szovegmeret);
        }
        szoveg[szocount] = buff;
        szocount++;
    }
    Stat *statisztika = Elemzes(szoveg, szovegmeret);
    PrintStat(statisztika);
    return 0;
}