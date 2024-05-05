/*
Given an M × N matrix of characters, find the length of the longest path in the matrix starting from a given character. All characters in the longest path should be increasing and consecutive to each other in alphabetical order.

We are allowed to search the string in all eight possible directions, i.e., North, West, South, East, North-East, North-West, South-East, South-West.

 For example, consider the following matrix of characters:

 [ D, E, H, X, B ] [ A, O, G, P, E ] [ D, D, C, F, D ] [ E, B, E, A, S ] [ C, D, Y, E, N ]
The length of the longest path with consecutive characters starting from character C is 6. The longest path is:

C(2, 2) —> D(2, 1) —> E(3, 2) —> F(2, 3) —> G(1, 2) —> H(0, 2)

*/
#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int r[]={-1,0,1,-1,1,-1,0,1};
int c[]={1,1,1,0,0,-1,-1,-1};

bool isSafe(int i,int j){
    return i >= 0 & i < n & j>=0 & j < n;
}
void getDFS(string (&board)[n], bool (&btable)[n][n], char start,int i,int j, set<char>& bag){
    if(btable[i][j]) return;
    if(bag.find(board[i][j]) != bag.end()) return;
    cout << board[i][j] << " -> ";
    btable[i][j] = true;
    bag.insert(board[i][j]);
    for(int k = 0; k < 8; ++k ){
        if(isSafe(i+r[k],j+c[k]) &&(char)(start+1) == board[i+r[k]][j+c[k]])
            
            getDFS(board,btable,(char)(start+1), i+r[k],j+c[k], bag);
        // if(isSafe(i+r[k],j+c[k]) && !btable[i+r[k]][j+c[k]] && (char)(start+1) == board[i+r[k]][j+c[k]]){             
        // }
    }

}

void get_longest_sequence(string (&board)[n]){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char start = board[i][j];
            bool btable[5][5] = {
                {false,false, false, false,false},
                {false,false, false, false,false},
                {false,false, false, false,false},
                {false,false, false, false,false},
                {false,false, false, false,false},
            };
            set<char> bag;
            getDFS(board,btable,start,i,j,bag);
            cout << endl;
        }
    }
}

int main(){
    string board[5] =  {
        { 'D', 'E', 'H', 'X', 'B' },
        { 'A', 'O', 'G', 'P', 'E' },
        { 'D', 'D', 'C', 'F', 'D' },
        { 'E', 'B', 'E', 'A', 'S' },
        { 'C', 'D', 'Y', 'E', 'N' }
    };
    bool btable[5][5] = {{false}};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            btable[i][j] = false;
        }
    }
    get_longest_sequence(board);
}