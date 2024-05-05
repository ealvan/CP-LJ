/*

Recently Luba bought a very interesting book. She knows that it will take t seconds to read the book. Luba wants to finish reading as fast as she can.

But she has some work to do in each of n next days. The number of seconds that Luba has to spend working during i-th day is ai. If some free time remains, she can spend it on reading.

Help Luba to determine the minimum number of day when she finishes reading.

It is guaranteed that the answer doesn't exceed n.

Remember that there are 86400 seconds in a day.

Input
The first line contains two integers n and t (1 ≤ n ≤ 100, 1 ≤ t ≤ 106) — the number of days and the time required to read the book.

The second line contains n integers ai (0 ≤ ai ≤ 86400) — the time Luba has to spend on her work during i-th day.

Output
Print the minimum day Luba can finish reading the book.
*/
#include <bits/stdc++.h>

using namespace std;

int getNDay(int& n, int &t, vector<int>& days){
    int cd = 0;//days counter
    for(int i = 0; i < n; ++i){
        int freetime = 86400 - days[i];//get freetime
        cd++; //increment count day
        t -= freetime; //subtract free time from t days to read the book
        if(t <= 0){//it means that book is readed
            break;
        }
    }
    if(t > 0){//it means lack of days with free time.
        return -1;
    }
    return cd;
}

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> days;
    int item;
    for(int i = 0; i < n; ++i){
        cin >> item;
        days.push_back(item);
    }
    int cd =  getNDay(n, t, days);
    cout << cd << endl;
}