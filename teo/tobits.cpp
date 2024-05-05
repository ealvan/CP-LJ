#include <bits/stdc++.h>
using namespace std;

int convertobits(int n){
    string ans;
    while(n>0){
        int b = n%2;
        ans.push_back(b+'0');
        n =n/2;
    }
    int zeros = 0;
    while(zeros < ans.size() && ans[zeros] == '0'){
        zeros++;
    }
    return zeros;
}

int main(){
    cout << convertobits(14) << endl;
    int n;
    cin >> n;
    cout << __builtin_ctz(n) << endl;
    return 0;
}