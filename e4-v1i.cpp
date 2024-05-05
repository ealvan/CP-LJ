#include <bits/stdc++.h>
using namespace std;

int getPerfectNumber(int i){
    return 19 + 9*(i-1);
}



int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(int item :  a){
        int res = getPerfectNumber(item);
        cout <<"item: "<<item <<" res: "<< res << endl;
    }
}