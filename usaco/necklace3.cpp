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
#include <map>
#include <algorithm>

using namespace std;

template<typename tupleType>
void DisplayTupleInfo(tupleType& tup){
    const int members = tuple_size<tupleType>::value;
    cout << "###############################################\n";
    cout << "Amount: "<< get<0>(tup) << endl;
    cout << "Init: "<<  get<1>(tup) << endl;
    cout << "End: "<<  get<2>(tup) << endl;
}

int getIndex(int index, int amount,  int wheel){
    if(index + amount < 0 ){
        return wheel + amount;
    }
    return index + amount;
}

bool isH(string& necklace){
    map<char, int> record;
    record.insert(pair('r',0));
    record.insert(pair('b',0));
    record.insert(pair('w',0));
    for(char c: necklace){
        record[c]++;
    }
    
    return record['r'] == 0 || record['b'] == 0;
}

tuple<int,int,int> getHLong(int index, string& necklace){
    char stated = necklace[index];
    int count = 0;
    int m = index,n = index;
    bool hasEnd1 = false;
    bool hasEnd2 = false;
    if(isH(necklace)){
        return tuple(necklace.size(), 0 , necklace.size() -1 );
    }
    while(hasEnd1 == false || hasEnd2 == false){
        int nextm = getIndex(m, -1, necklace.size());//r
        int nextn = (n+1)%necklace.size();//w -> r
        if(necklace[nextm] == stated || necklace[nextm] == 'w'){
            m = nextm;
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
    }
    count+=1;
    return tuple(count, m, n);
}

void addRange(vector<int>& v, int start, int end, int wheel){
    for(int i = start; i != end; i = (i+1)% wheel){
        v.push_back(i);
    }
    v.push_back(end);
}

void displayRange(vector<int> v){
    for(int item: v){
        cout << item << " ";
    }
    cout << endl;
}

template<typename tupleType>
int intersect(tupleType& rangeA, tupleType& rangeB, string& necklace){
    int start1 = get<1>(rangeA);
    int end1 = get<2>(rangeA);
    int start2 = get<1>(rangeB);
    int end2 = get<2>(rangeB);
    // if(start1 > end1){
    //     // over  // . . x . . n-1 0 . . y
    //     // normal// init . . x . . y . . . . end
    // }
    vector<int> a;
    addRange(a, start1, end1, necklace.size());
    vector<int> b;
    addRange(b, start2, end2, necklace.size());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // displayRange(a);
    // displayRange(b);
    
    vector<int> intersection;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));
    // cout << "#elements: "<< intersection.size() << endl;
    /*
    wrbwb - len: 5 
    0 - 1 | 0 1
    2 - 0 | 2 3 4 0 
    intersection = 1  
    ------
    wrwrbwbw - len: 8
    7 - 3 | 7 0 1 2 3  
    4 - 0 | 4 5 6 7 0
    intersection = 2 
    */
    return intersection.size();
}

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int beads;
    fin >>  beads;
    string necklace;
    fin >> necklace;

    // vector<int> lens;

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
            // if(intersect(data,tmp, necklace)){
            //     cout << "INTERSECADO\n";
            // }
            maxx = max(get<0>(data)+ get<0>(tmp) - intersect(data,tmp, necklace),maxx);
            // cout << "len: "<< (get<0>(data)+ get<0>(tmp) - intersect(data,tmp, necklace)) <<endl;
            if(i > get<2>(data)){
                // cout << "i: "<< i << " - end data: "<<get<2>(data)<<endl;
                break;
            }
            i = get<2>(data);
            //LACK OF INTERSECT FUNCTION
            // DisplayTupleInfo(data);
            // DisplayTupleInfo(tmp);
            // cout << "Intersecado: "<< intersect(data,tmp, necklace) << endl;
            // lens.push_back( get<0>(data) );

            // cout << "\n next i: " << ( get<2>(data)+1 ) % necklace.size() << endl;

            // tmp = getHLong( (i+1) % necklace.size() , necklace);
        }
    }
    if(end){
        tmp = getHLong((get<2>(data)+1)%necklace.size(), necklace);
        maxx = max(get<0>(tmp)+get<0>(data) - intersect(tmp,data,necklace),maxx );
    }
    if(maxx == -1){
        fout << necklace.size()<<endl;        
    }else
        fout << maxx << endl;
}