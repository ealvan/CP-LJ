#include <bits/stdc++.h>
using namespace std;
// int costs[] = {1'234'567,123'456, 1'234};
int costs[] = {3,5};
string getBudget(int n){
    cout<<"budget: " << n << endl;
    if(n < 0){
        return "NO";
    }
    if(n == 0){
        return "YES";
    }
    
    for(int cost : costs){
        
        if(getBudget(n-cost) == "YES"){
            return "YES";
        }
    }

    return "NO";
}
int main(){
    int n;
    cin >> n;
    
    string a = getBudget(n);
    cout << a << endl;
}