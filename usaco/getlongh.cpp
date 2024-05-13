#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include<string.h>
#include <map>

using namespace std;
int getIndex(int index, int amount,  int wheel){
    if(index + amount < 0 ){
        return wheel + amount;
    }
    return index + amount;
}
template<typename tupleType>
void DisplayTupleInfo(tupleType& tup){
    const int members = tuple_size<tupleType>::value;
    cout << "###############################################\n";
    cout << "Amount: "<< get<0>(tup) << endl;
    cout << "Init: "<<  get<1>(tup) << endl;
    cout << "End: "<<  get<2>(tup) << endl;
}
bool isH(string& necklace){
    map<char, int> record;
    record.insert(pair('r',0));
    record.insert(pair('b',0));
    record.insert(pair('w',0));
    for(char c: necklace){
        record[c]++;
    }
    // if(record['r'] != 0 && record['b'] != 0){
    //     return false;
    // }
    
    return record['r'] == 0 || record['b'] == 0;
}
tuple<int,int,int> getHLong(int index, string& necklace){
    char stated = necklace[index];
    int count = 0;
    // cout << "Size: "<<necklace.size() << endl;
    int m = index,n = index;
    // int m = getIndex(index, -1, necklace.size());
    // int n = (index+1)%necklace.size();
    // bool isH = false;
    bool hasEnd1 = false;
    bool hasEnd2 = false;
    if(isH(necklace)){
        return tuple(necklace.size(), 0 , necklace.size() -1 );
    }
    while(hasEnd1 == false || hasEnd2 == false){
        int nextm = getIndex(m, -1, necklace.size());//r
        int nextn = (n+1)%necklace.size();//w -> r
        if(necklace[nextm] == stated || necklace[nextm] == 'w'){
            // cout << "m: " << m <<" i: "<< getIndex(m, -1, necklace.size()) <<" len: "<<necklace.size() <<endl;
            m = nextm;
            // m = (m-1)%necklace.size();
            count++;
        }else{
            hasEnd1 = true;
        }
        if(necklace[nextn] == stated || necklace[nextn] == 'w'){
            n = nextn;
            count++;
        }else{
            hasEnd2 = true;
        }
        // if(n-m==1 || m == n){
        //     isH = true;
        //     break;
        // }
    }
    // if(isH){
    //     return tuple(necklace.size(), 0, necklace.size()-1);
    // }
    // m = (m+1)%necklace.size();
    // // n = (n-1)%necklace.size();
    // n = getIndex(n, -1, necklace.size());
    // if(m > n){
    //     count = necklace.size() - m + n + 1;
    // }else{
    //     count = n-m+1;
    // }
    count+=1;
    return tuple(count, m, n);
}

int main(){
    int n;
    cin >> n;
    string necklace;
    cin >> necklace;
    for(int i = 0; i < necklace.size(); ++i){
        if(necklace[i] != 'w'){
            tuple<int,int,int> res = getHLong(i, necklace);
            DisplayTupleInfo(res);
        }
    }
}