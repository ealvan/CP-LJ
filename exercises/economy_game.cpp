#include <bits/stdc++.h>
using namespace std;

/*
Kolya is developing an economy simulator game. His most favourite part of the development process is in-game testing. Once he was entertained by the testing so much, that he found out his game-coin score become equal to 0.

Kolya remembers that at the beginning of the game his game-coin score was equal to n and that he have bought only some houses (for 1 234 567 game-coins each), cars (for 123 456 game-coins each) and computers (for 1 234 game-coins each).

Kolya is now interested, whether he could have spent all of his initial n game-coins buying only houses, cars and computers or there is a bug in the game. Formally, is there a triple of non-negative integers a, b and c such that a × 1 234 567 + b × 123 456 + c × 1 234 = n?

*/
int costs[] = {1'234'567, 123'456, 1'234};
//problem, you need to fic to values, so the remainder & c3 is 0 :)
//c1*a + c2*b + c3*c, where a,b,c >= 0 && a < n/c1 & b < n/c2 & c < n/c3 


int main(){
    int n;
    cin >> n;
    int c1times = n/costs[0];
    int c2times = n/costs[1];
    int mount = 0;
    for(int i = 0; i <= c1times; ++i){
        for(int j = 0; j <= c2times; ++j){
            mount = costs[0]*i + costs[1]*j;
            int remainder = n - mount;
            if(remainder < 0) break;//if is 0, is 

            if(remainder % costs[2] == 0){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}