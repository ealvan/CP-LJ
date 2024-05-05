#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 2, 3};

int getFormas(int m, int formas) {
    if (m == 0) {
        return 1;
    }
    if( m < 0){
        return 0;
    }
    int total = 0;
    for (auto coin : coins) {
        if (m - coin >= 0) {
            total += getFormas(m - coin, formas);
        }
    }
    return total;
}

int main() {
    int m = 5;
    int formas = 0;
    int f = getFormas(m, formas);
    cout << f << endl;
    return 0;
}
