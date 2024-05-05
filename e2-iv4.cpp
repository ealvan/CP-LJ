#include <bits/stdc++.h>
using namespace std;
enum code{
    EQUAL = 0,
    GREATER = 1,
    LESSER = -1
};

int getLE(int &n, const vector<int>& days){
    if(n <= 2){
        return 0;
    }
    /*
    edge cases:
    1
    1 1
    5
    219 198 198 415 771
    */
    vector<int>::const_iterator ci = days.cbegin();

    code pre = *ci < *(ci +1) ? GREATER : *ci != *(ci +1) ? LESSER : EQUAL;

    int c = 0;

    for(vector<int>::const_iterator cit = days.cbegin()+1 ; cit != days.cend()-1; ++cit){
        /* I known the past, so I just need to see the future :) */
        code oldpre = pre;
        code lextremum = EQUAL;

        if(oldpre == GREATER){
            lextremum = *cit > *(cit+1) ? GREATER : EQUAL;
        }else if(oldpre == LESSER){
            lextremum = *cit < *(cit+1) ? LESSER : EQUAL;
        }

        pre = *cit < *(cit+1) ? GREATER : *cit != *(cit +1) ? LESSER : EQUAL;

        if(lextremum == GREATER || lextremum == LESSER){
            ++c;
        }
        // cout <<"*me: c: "<< c << " olpre: " << oldpre << " currentval: "<< *cit << " current pre: "<< pre<<endl;
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