#include <bits/stdc++.h>
using namespace std;
int costs[] = {1'234'567,123'456,1'234};
string decision(int n, vector<bool>& ready, vector<string>& result){
    if(n < 0) return "NO";
    if(n == 0) return "YES";
    if(ready[n]) return result[n];
    for(int cost : costs){
        if(n - cost >= 0){
            string res = decision(n-cost, ready,result);
            result[n-cost] = res;
            if(res == "YES") return "YES";
        }
    }
    ready[n] = true;
    result[n] = "NO";
    return "NO";
}

void getBudget(int n){
    vector<bool> ready(n,false);
    vector<string> result(n, "");
    string res  = decision(n, ready, result);
    cout << res << "\n";
}

int main(){
    int n;
    cin >> n;
    getBudget(n);
}