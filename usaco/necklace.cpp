/*
ID: edsel.a1
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

template<typename tupleType>
void DisplayTupleInfo(tupleType& tup){
    const int members = tuple_size<tupleType>::value;
    cout << "###############################################\n";
    cout << "Amount: "<< get<0>(tup) << endl;
    cout << "Init: "<<  get<1>(tup) << endl;
    cout << "End: "<<  get<2>(tup) << endl;
}
template<typename tupleType>
bool intersect(tupleType& rangeA, tupleType& rangeB){
    int start1 = get<1>(rangeA);
    int end1 = get<2>(rangeA);
    int start2 = get<1>(rangeB);
    int end2 = get<2>(rangeB);
    return end1 >= start2;
}
/*
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
0123                        
*/
int getIndex(int index, int amount,  int wheel){
    if(index + amount < 0 ){
        return wheel + amount;
    }
    return index + amount;
}

tuple<int,int,int> getHLong(int index, string& necklace){
    char stated = necklace[index];
    int count = 0;
    // cout << "Size: "<<necklace.size() << endl;
    int m = (index-1)%necklace.size();
    int n = (index+1)%necklace.size();
    while(necklace[m] == stated || necklace[m] == 'w' || necklace[n] == stated || necklace[n] == 'w'){
        if(necklace[m] == stated || necklace[m] == 'w'){
            // cout << "m: " << m <<" i: "<< getIndex(m, -1, necklace.size()) <<" len: "<<necklace.size() <<endl;
            m = getIndex(m, -1, necklace.size());
            // m = (m-1)%necklace.size();
            count++;
        }
        if(necklace[n] == stated || necklace[n] == 'w'){
            n = (n+1)%necklace.size();
            count++;
        }
    }
    m = (m+1)%necklace.size();
    // n = (n-1)%necklace.size();
    n = getIndex(n, -1, necklace.size());
    if(m > n){
        count = necklace.size() - m + n + 1;
    }else{
        count = n-m+1;
    }
    return tuple(count, m, n);
}

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int beads;
    cin >>  beads;
    string necklace;
    cin >> necklace;
    // tuple<int,int,int> data = getHLong(3, necklace);
    // cout <<"char: "<< 3 << " - val: " <<necklace[3] << endl;
    // DisplayTupleInfo(data);
    vector<int> lens;

    tuple<int,int,int> data;
    tuple<int,int,int> tmp;
    int maxx = -1;
    bool end = false;
    for(int i = 0; i < beads; i++){
        if(necklace[i] != 'w' ){
            data = getHLong(i, necklace);
            if(get<2>(data)+1 >= necklace.size()){
                end = true;
                break;
            }
            tmp = getHLong( get<2>(data)+1, necklace);
            
            maxx = max(get<0>(data)+ get<0>(tmp),maxx);

            if(i > get<2>(data)){
                cout << "i: "<< i << " - end data: "<<get<2>(data)<<endl;
                break;
            }
            i = get<2>(data);

            DisplayTupleInfo(data);
            // lens.push_back( get<0>(data) );

            // cout << "\n next i: " << ( get<2>(data)+1 ) % necklace.size() << endl;

            // tmp = getHLong( (i+1) % necklace.size() , necklace);
        }
    }
    if(end){
        tmp = getHLong((get<0>(data)+1)%necklace.size(), necklace);
        maxx = max(get<0>(tmp), get<0>(data));
    }
    cout << maxx << endl;
    // cout << "###########################################################\n";
    // for(int i = 0; i < lens.size(); ++i){
    //     cout << lens[i] << " ";
    // }
    // cout << "\n###########################################################\n";
}