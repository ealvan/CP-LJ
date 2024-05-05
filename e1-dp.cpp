#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1,2,3};
vector<int> memo(5+1,-1);

int getFormas(int m, int formas){
    if(m == 0){
        return 1;
    }
    if(memo[m] != -1) return memo[m];
    memo[m] = 0;
    for(int coin : coins){
        if(m >= coin) memo[m] += getFormas(m - coin, formas);
    }
    return memo[m];
}

int main(){
    int m = 3;
    int formas = 0;
    int f = getFormas(m, 0);
    cout << f << endl;
}   