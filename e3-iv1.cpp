#include <bits/stdc++.h>

using namespace std;


/*
    pwww
*/

bool isPalindrome(string& word){
    int i = 0;
    int f = word.size()-1;
    bool isPal = true;
    for(int k = 0; k < word.size() && isPal && i <= f; ++k){
        if(word[i] != word[f]){
            isPal = false;
        }
        ++i;
        --f;
    }
    return isPal;
}
bool isPal(string& word){
    string tword = word;
    reverse(word.begin(), word.end());
    return word == tword;
}
int getLongestNonPalWord(string word, int& index){
    if(!isPal(word)){
        return word.size();
    }
    if(word.size() <= index) return 0;
    string rword = word.substr(0,word.size()-index);
    return getLongestNonPalWord(rword, ++index);
}

int main(){
    string word;
    cin >> word;
    int index = 1;
    int r = getLongestNonPalWord(word, index);
    cout << r << endl;
}