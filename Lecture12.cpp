#include "bits/stdc++.h"
using namespace std;

//1st Question
bool Yexist(vector<vector<char>> &board,int m,int n, int row,int col,string curr,int idx,string word,vector<vector<bool>> &visited){
    if(idx == word.size()){
        return true;
    }

    if(row<0 || row>=m || col<0 || col>=n || word[idx]!=board[row][col]){
        return false;
    }

    if(idx > word.size()){
        return false;
    }


    if(visited[row][col]){
        return false;
    }

    visited[row][col] = true;
    bool top = Yexist(board,m,n,row-1,col,curr+board[row][col],idx+1,word,visited);
    bool bot = Yexist(board,m,n,row+1,col,curr+board[row][col],idx+1,word,visited);
    bool left = Yexist(board,m,n,row,col-1,curr+board[row][col],idx+1,word,visited);
    bool right = Yexist(board,m,n,row,col+1,curr+board[row][col],idx+1,word,visited);
    visited[row][col] = false;

    return top || bot || left || right;

}

bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visited(row,vector<bool>(col,false));

    string temp = "";
    if((temp+board[0][0])==word){
        return true;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(Yexist(board,row,col,i,j,"",0,word,visited)){
                return true;
            }
        }
    }
    return false;
}


//2nd Question
double myPow(double x, int n) {
    if(n==0) return 1;
    if(n<0) {
        n = abs(n);
        x = 1/x;
    }
    if(n%2==0){
        return myPow(x*x, n/2);
    }
    else{
        return x*myPow(x, n-1);
    }
}



//3rd Question
void allsubset(vector<int> &nums,int start,vector<int> &temp,vector<vector<int>> &result){
    if(start>=nums.size()){
        result.push_back(temp);
        return;
    }
    temp.push_back(nums[start]);
    allsubset(nums,start+1,temp,result);
    temp.pop_back();
    allsubset(nums,start+1,temp,result);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    vector<int> temp;
    allsubset(nums,0,temp,result);
    sort(result.begin(), result.end());
    // Removing duplicates
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main(){
    cout<<"Lecture 12"<<endl;
    return 0;
}