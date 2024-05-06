/*
ID: edsel.a1
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
//error: a%0 gives "floating point number exception"
int main(){
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    
    int n;
    fin >> n;
    map<string,int> records;
    string names[n];
    string item;
    for(int i = 0; i < n; ++i){
        fin >> item;
        records.insert(make_pair(item, 0));
        names[i] = item;
    }
    string giver;
    while(fin >> giver){
        
        int amount, gifts;
        fin >> amount >> gifts;
        records[giver] -= amount;
        records[giver] += gifts != 0 ? (amount % gifts) : amount;
        string given;
        for(int i = 0; i < gifts; ++i){
            fin >> given;
            records[given] += int(amount/gifts);
        }
    }
    for(string person: names){
        fout << person << " " << records[person] << '\n';
    }

}