#include <bits/stdc++.h>
using namespace std;
/*
Given an M × N boggle board, find a list of all possible words that can be formed by a sequence of adjacent characters on the board.

We are allowed to search a word in all eight possible directions, i.e., North, West, South, East, North-East, North-West, South-East, South-West, but a word should not have multiple instances of the same cell.

 Consider the following the traditional 4 × 4 boggle board. If the input dictionary is [START, NOTE, SAND, STONED], the valid words are [NOTE, SAND, STONED]
 
*/
/*
    -1,1    0,1   1,1    
    -1,0    0,0   1,0
    -1,-1   0,-1  1,-1
*/
vector<tuple<int,int>> directions = {
    tuple<int,int>(-1,1),
    tuple<int,int>(0,1),
    tuple<int,int>(1,1),
    tuple<int,int>(-1,0),
    tuple<int,int>(1,0),
    tuple<int,int>(-1,-1),
    tuple<int,int>(0,-1),
    tuple<int,int>(1,-1),
};

bool isSafe(tuple<int,int>& point, const vector<string>& board){
    if(get<0>(point) >= 0 && get<0>(point) < board.size() && 
        get<1>(point)>= 0 && get<1>(point) < board.size()){
            return true;
    }
    return false;
}

void dfs(string& word, tuple<int,int> point, const vector<string>&board, vector<vector<bool>>&visited, int counter, bool& result){

    // if(counter >= word.size()){
    //     cout << "|||||"<<endl;
    //     result = false;
    //     return;
    // }
    if(board[get<0>(point)][get<1>(point)] != word[counter]){
        return;
    }
    visited[get<0>(point)][get<1>(point)] = true;
    printf("point: (%d,%d) || counter: %d\n",get<0>(point),get<1>(point),counter);
    cout <<"board: "<< board[get<0>(point)][get<1>(point)] << " - word: "<< word[counter] << endl;

    if(counter == word.size()-1 && board[get<0>(point)][get<1>(point)] == word[counter]){
        result = true;
        cout << "****" << endl;
        return;
    }

    for(tuple<int,int> dir: directions){
        tuple<int,int> newpoint(
        make_tuple(
            get<0>(point)+get<0>(dir), 
            get<1>(point)+get<1>(dir)
            )
        );
        if(isSafe(newpoint, board) && !visited[get<0>(newpoint)][get<1>(newpoint)]){
            int newcounter = counter+1;            
            dfs(word,newpoint, board, visited, newcounter, result);
        }
    }
}

vector<int> getYCoordinates(const char init, string word){
    vector<int> ys;
    size_t pos = word.find(init, 0);
    while(pos != string::npos){
        ys.push_back(pos);
        size_t newpos = pos+1;
        pos = word.find(init, newpos);
    }
    return ys;
}

vector<tuple<int,int>> getCoordinate(const char init, const vector<string>& board){
    vector<tuple<int,int>> points;
    size_t pos;
    
    for(int i = 0; i < board.size(); ++i){
        vector<int> ys = getYCoordinates(init, board[i]);
        for(int y: ys){
            points.push_back(tuple(i,y));
        }
    }
    return points;
}

vector<string> validate(const vector<string>& board, const vector<string> words){
    vector<string> selectedwords;
    for(string word: words){
        vector<tuple<int,int>> points = getCoordinate(word[0], board);
        vector<vector<bool>> visited(board.size(), vector<bool>(board.size(), false));
        int start = 0;
        for(tuple<int,int> point: points){
            bool isIn = false;
            dfs(word, point, board, visited,start, isIn);
            cout << endl;
            if(isIn){
                selectedwords.push_back(word);
            }
        }
    }
    return selectedwords;
}

int main(){
    vector<string> board = {
        "MSEF",
        "RATD",
        "LONE",
        "KAFB"
    };
    vector<string> words = {"START","NOTE","SAND", "STONED"};

    vector<string> swords = validate(board, words);
    for(string word: swords){
        cout <<word << endl;
    }
}