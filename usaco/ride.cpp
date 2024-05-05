/*
ID: edsel.a1
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//(A * B) mod C = (A mod C * B mod C) mod C

int getRemainder(string item, int& mod){
    int ra = 1;
    for(char ch: item){
        ra = ra * int(ch-'A'+1) % mod;
        ra = ra % mod;
    }
    return ra;
}

int main(){
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string a,b;
    fin >> a >> b;
    int mod = 47;
    string ra,rb;
    ra = getRemainder(a, mod);
    rb = getRemainder(b, mod);
    if(ra == rb){
        fout << "GO\n";
    }else fout << "STAY\n";
    return 0;
}
