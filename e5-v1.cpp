#include <bits/stdc++.h>
using namespace std;
int getMask(int a){
    int ta = a;
    string mask = "";
    while( a > 0){
        int digit = a%10;
        a = a/10;
        if(digit == 4 || digit == 7){
            mask += to_string(digit);

        }
    }
    if(mask.empty()) return 0;
    reverse(mask.begin(), mask.end());
    // cout <<"a: "<<ta<< " mask : "<< mask <<"*"<< endl;
    return stoi(mask);
}
int getMask(string a){
    string mask;
    for(char ch : a){
        if(ch == '7' || ch =='4'){
            mask+=ch;
        }
    }
    return stoi(mask);
}
int getLuckyNumber(int a, int b){
    if(b > a){
        return b;
    }
    //first get the len of b digits
    int lbi = to_string(b).length();
    // cout << "len b: "<<lbi<<endl;
    //cut the a number - b digits
    string cut = "1";
    for(int i = 0; i < lbi; ++i){
        cut += '0';
    }
    int ac = a/stoi(cut);
    // cout << "a: "<<a << " /"<<cut<<" : "<<ac<<endl;
    //concatenate "a" + "b"
    string nnew = to_string(ac) + to_string(b); 
    // cout << "a+b: "<< nnew<< endl;
    //convert to number
    int nnewi = stoi(nnew);
    //check is the new number > a original

    if( nnewi > a) return nnewi; 
    //return c;
    //else add to the new number 1+(0)*b digits
    return nnewi + stoi(cut);
}
int getLuckyNumber2(int a, int b){
    // if(b > a) return b;
    while(getMask(a) != b){
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