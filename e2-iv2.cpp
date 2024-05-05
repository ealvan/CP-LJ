#include <bits/stdc++.h>
using namespace std;

int getLE(int &n, const vector<int>& days){
    if(n <= 2){
        return 0;
    }
    vector<int>::const_iterator ci = days.cbegin();
    bool pre = *ci < *(ci +1) ? 1 : 0;
    int c = 0;
    for(vector<int>::const_iterator cit = days.cbegin()+1 ; cit != days.cend()-1; ++cit){
        bool oldpre = pre;
        pre = *cit < *(cit+1) ? 1: 0;
        /*
        old PRE:
            1 - actual > anterior
            0 - actual < anterior
        current PRE
            1 - actual < posterior
            0 - actual > posterior
        */
       bool lmin = oldpre == false && pre;
       bool lmax = oldpre && pre == false;
       if(lmin | lmax){
        ++c;
       }    
    //    cout <<"c: "<< c << " olpre: " << oldpre << " currentval: "<< *cit << " current pre: "<< pre<<endl;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    vector<int> days;
    int item;
    for(int i = 0; i < n; ++i){
        cin >> item;
        days.push_back(item);
    }

    int le = getLE(n,days);
    cout << le << endl;
}