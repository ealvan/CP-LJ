#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int getLE_me(int &n, const vector<int>& days){
    if(n <= 2){
        return 0;
    }
    vector<int>::const_iterator ci = days.cbegin();
    bool pre = *ci < *(ci +1);
    int c = 0;
    for(vector<int>::const_iterator cit = days.cbegin()+1 ; cit != days.cend()-1; ++cit){
        bool oldpre = pre;
        bool lextremum = false;
        if(oldpre){
            lextremum = *cit > *(cit+1); 
        }else{
            lextremum = *cit < *(cit+1);
        }
        pre = *cit < *(cit+1);
        /*
        old PRE:
            1 - actual > anterior
            0 - actual < anterior
        current PRE
            1 - actual < posterior
            0 - actual > posterior
        */
    //    bool lmin = oldpre && pre;
    //    bool lmax = oldpre && pre;
        if(lextremum){
                ++c;
        }
        cout <<"*me: c: "<< c << " olpre: " << oldpre << " currentval: "<< *cit << " current pre: "<< pre<<endl;
    }
    return c;
}
int getLE_normal(int n, const vector<int>& arr){
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
        cout <<"*normal : c: "<< lextrem << " pre: " << (pre < val) << " currentval: "<< *it << " pos: "<< (val < pos)<<endl;

    }
    return lextrem;
}

void compare(int &i, fstream& f){
    int n;
    f >> n;
    vector<int> days;
    int item;
    for(int i = 0; i < n; ++i){
        f >> item;
        days.push_back(item);
    }

    int lenorm = getLE_normal(n,days);
    int leme = getLE_me(n, days);
    cout << "#"<<i<<" n: "<<n<<" normal: "<< lenorm << " me: "<< leme;    
    if(lenorm != leme){
        cout << " ERROR here";
    }
    cout << endl;
}

int main(){
    fstream filetest;
    filetest.open("error.txt", ios_base::in);
    int i = 1;
    if(filetest.is_open()){
        while(filetest.good()){
            compare(i, filetest);
            i++;
        }
        filetest.close();
    }
}