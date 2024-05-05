#include <bits/stdc++.h>
using namespace std;

int getLE(int n, const vector<int>& arr){
    if(n == 1){
        return 0;
    }
    int lextrem = 0;
    for(vector<int>::const_iterator it = arr.cbegin()+1; it != arr.cend()-1 ; ++it){
        int val = *it;
        int pre = *(it-1);
        int pos = *(it+1);
        bool lmin = val < pre && val < pos;
        bool lmax = val > pre && val > pos;
        if(lmin | lmax) ++lextrem; 
    }
    return lextrem;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    int item;
    for(int i = 0; i < n ; ++i){
        cin >> item;
        arr.push_back(item);
    }
    int le = getLE(n,arr);
    cout << le << endl;
    
}