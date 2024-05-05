#include <bits/stdc++.h>
using namespace std;

int getMask(string a){
    string mask;
    for(char ch : a){
        if(ch == '7' || ch =='4'){
            mask+=ch;
        }
    }
    if(mask.empty()) return 0;
    return stoi(mask);
}

int getLuckyNumber2(int a, int b){
    // if(b > a) return b;
    a+=1;
    while(getMask(to_string(a)) != b){
        ++a;
    }
    return a;
}

int main(){
    int a, b;
    cin >> a >> b;
    int res = getLuckyNumber2(a,b);
    cout << res << endl;
}