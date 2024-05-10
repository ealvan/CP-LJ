/*
ID: edsel.a1
TASK: friday
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

bool isLeap(int y){
    if(y%100 == 0){
        return y % 400 == 0;
    }
    return y % 4 == 0;
}

enum Months{
    ENERO = 1,
    FEBRERO,
    MARZO,
    ABRIL,
    MAYO,
    JUNIO,
    JULIO,
    AGOSTO,
    SEPTIEMBRE,
    OCTUBRE,
    NOVIEMBRE,
    DICIEMBRE,
    ENDM
};

enum Days{
    SABADO=0,
    DOMINGO,
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    END
};

int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    
    int n;
    fin >> n;

    map<Months,Days> records;

    records.insert(make_pair(ENERO, SABADO));
    records.insert(make_pair(FEBRERO, MARTES));
    records.insert(make_pair(MARZO, MARTES));
    records.insert(make_pair(ABRIL, VIERNES));
    records.insert(make_pair(MAYO, DOMINGO));
    records.insert(make_pair(JUNIO, MIERCOLES));
    records.insert(make_pair(JULIO, VIERNES));
    records.insert(make_pair(AGOSTO, LUNES));
    records.insert(make_pair(SEPTIEMBRE, JUEVES));
    records.insert(make_pair(OCTUBRE, SABADO));
    records.insert(make_pair(NOVIEMBRE, MARTES));
    records.insert(make_pair(DICIEMBRE, JUEVES));

    // for(auto element = records.begin(); element != records.end(); element++){
    //     cout << element->first << " -> " << element->second << endl;
    // }
    // cout << "*********************"<<endl;

    map<Days,int> book;
    
    book.insert(make_pair(LUNES, 1));
    book.insert(make_pair(MARTES, 3));
    book.insert(make_pair(MIERCOLES, 1));
    book.insert(make_pair(JUEVES, 2));
    book.insert(make_pair(VIERNES, 2));
    book.insert(make_pair(SABADO, 2));
    book.insert(make_pair(DOMINGO, 1));
    
    for(int y = 1901; y <= 1900 + n - 1; y++){
        for(Months m = ENERO; m < ENDM; m = static_cast<Months>(m+1)){
            int next_day;
            if(isLeap(y-1)){
                if(m < 3){
                    next_day = records[m]+2;
                    records[m] = static_cast<Days>(next_day % 7);
                }else{
                    next_day = records[m]+1;
                    records[m] = static_cast<Days>(next_day % 7);
                }
            }else if(isLeap(y)){
                if(m < 3){
                    next_day = records[m]+1;
                    records[m] = static_cast<Days>(next_day % 7);
                }else {
                    next_day = records[m]+2;
                    records[m] = static_cast<Days>(next_day % 7);
                }
            }else{
                next_day = records[m]+1;
                records[m] = static_cast<Days>(next_day % 7);
            }            
            book[records[m]]++;
        }
    }
    /*
    1900 + N - 1 / N = 8
    1900    1901    1902    1903    1904    1905    1906    1907    1908    1909    1910    1911    1912
    Sab     +1      +1      +1      +1      +1      +1      +2
            d       l       m       m       j       v       d
    Dom     l       m       m       j       v       s       l
    Vie     s       d       l       m       m       j       v
    
    */
    // for(auto element = records.begin(); element != records.end(); element++){
    //     cout << element->first << " -> " << element->second << endl;
    // }
    for(int day = SABADO; day != END; day++){
        Days mday = static_cast<Days>(day);
        fout << book[mday] << (mday == VIERNES ? "" : " ");
    }
    fout << endl;
}