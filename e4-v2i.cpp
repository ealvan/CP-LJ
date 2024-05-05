#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int n){
    int amount = 0;
    while(n > 0){
        int digit = n%10;
        n = n/10;
        amount += digit;
    }
    return amount == 10;
}

int getNPerfectNumber(int n, int (&buffer)[10000]){
    if(buffer[n] != 0)
        return buffer[n];
    int x = n;
    while(x >= 0 && buffer[x] == 0){
        x--;
    }
    for(int k = x; k <= n;){
        int number = buffer[k]+1;
        while(!isPerfect(number)){
            number++;
        }
        buffer[++k] = number;
    }
    return buffer[n];
}

int main(){
    int n;
    cin >> n;
    n = n-1;
    int buffer[10000] = {0};
    buffer[0] = 19;
    int re = getNPerfectNumber(n, buffer);
    cout << re << endl;

}