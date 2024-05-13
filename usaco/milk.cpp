/*
ID: edsel.a1
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum Flags{
    INIT=1,
    END=-1,
    IDLE=0
};

template< typename tupleType>
void display(tupleType& mt){
    cout << "time: "<<get<0>(mt)<<" flag: "<< get<1>(mt)<<endl;
}

int main(){
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int n;
    fin >> n;

    vector<tuple<int, Flags>> schedule;
    schedule.assign(2*n, tuple(0,IDLE));
    int init, end;
    int count = 0;

    for(int i = 0; i < 2*n; i+=2){
        fin >> init >> end;
        schedule[i] = tuple(init, INIT);
        schedule[i+1] = tuple(end, END);    
    }

    sort(schedule.begin(), schedule.end(), 
        [](const tuple<int,Flags>& a, const tuple<int,Flags>& b ) -> bool{
            int h1 = get<0>(a);
            int h2 = get<0>(b);
            return h1 < h2;
        });

    // for(tuple<int,int> item : schedule){
    //     display(item);
    // }
    int s = 0,e = 0;
    int cs= 0, ce = 0;    
    int c = 0;
    int cc = 0;
    for(int i = 0; i < schedule.size() ; ++i){
        tuple<int,Flags>& current = schedule[i];
        cc += get<1>(current);

        if(c == 0 && cc == 1){
            cs = get<0>(current);
            if(e - cs == 0){
                tuple<int,Flags>& before = schedule[i-1];
                Flags before_f = get<1>(before);
                Flags current_f = get<1>(current);
                get<1>(before) =  current_f;
                get<1>(current) =  before_f;
            }
            s = cs;
        }
        if(c == 1 && cc == 0){
            ce = get<0>(current);
            e = ce;
        }
        c = cc;
    }
    // cout << "******************************************"<<endl;
    // for(tuple<int,int> item : schedule){
    //     display(item);
    // }

    int cursor = 0;
    int current_cursor = 0;
    int maxx_work = 0;
    int maxx_idle = 0;
    int init1= 0, end1=0;
    tuple<int, Flags> current;
    init1 = get<0>(schedule[0]);
    cursor = 1;
    current_cursor = cursor;
    int transmisor = -1;
    for(int i = 1; i < schedule.size(); ++i){
        
        current = schedule[i];//1000        
        current_cursor += get<1>(current);

        if(cursor == 0 && current_cursor == 1){//Entrada
            init1 = get<0>(current);
            maxx_idle = max(init1 - end1, maxx_idle);
        }
        if( cursor == 1 && current_cursor== 0){//salida
            end1 = get<0>(current);
            maxx_work = max(end1 - init1, maxx_work );            
        }
        cursor = current_cursor;
    }

    fout << maxx_work << " " << maxx_idle << endl;
}
/*
        C-1  C
    +1  -1  +1  -1
    50 200 200 300
0   1   0   1   0
    +1  +1  -1  -1
0   1   2   1   0
6
100 200
200 400
400 800
800 1600
50 100
1700 3200
*
-----------------------------------------------
init2: 200 end2: 200
init2: 400 end2: 400
init2: 800 end2: 800
init2: 1600 end2: 1700
-----------------------------------------------

1-0 entrada
0-1 salida
    +1 +1  -1  +1  -1  +1  -1  +1  -1  +1   -1  -1
0   1   2   1   2   1   2   1   2   1   2   1   0
    +1 +1  -1  -1  +1  -1  +1  -1  +1  -1   +1  -1
0   1   2   1   0   1   0   1   0   1   0   1   0
0   s   -       e   s   e   s   e   s   e   s   e
                2   2   4   4   8   8   16  17
                max += ant + current
                max += ant_inter
0   e   -   -   -   -   -   -   -   -   -   -   s
    +1 +1  -1  -1  +1  -1  +1  -1  +1  -1   +1   -1
    50 100 100 200 200 400 400 800 800 1600 1700 3200
0   1   2   1   2   1   2   1   +1  -1   0   1   0
0   1   2   1   0   1   0   1   0   1   0   1   0
wt  i           o   i   o   i   o   i   o   i   o
it  
-----------------------------------------------------
1 50 200 -> 150
2 200 400 -> 200
3 400 800 -> 400
4 800 1600 -> 800
5 1700 3200 -> 1500
-----------
init1: 50 end1: 200
init1: 200 end1: 400
init1: 400 end1: 800
init1: 800 end1: 1600
init1: 1700 end1: 3200
-----------------------------------------------------
-----------------
4
100 200
201 301
302 402
403 503
-----------------
5
300 500
600 700
675 800
900 1000
988 1200

    +1  -1  +1  +1  -1  -1  +1  +1  -1   -1
    300 500 600 675 700 800 900 988 1000 1200 
0   1   0   1   2   1   0   1   2   1    0
wt  200 200 300
it  100 100


*/