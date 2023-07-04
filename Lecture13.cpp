#include "bits/stdc++.h"
using namespace std;

// 1st Question
bool check(vector<vector<char>>& board, int row, int col, char c)
{
    for(int i = 0; i < 9; i++)
        if(board[i][col] == c)
            return false;

    for(int i = 0; i < 9; i++)
        if(board[row][i] == c)
            return false;

    int x0 = (row/3) * 3, y0 = (col/3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[x0 + i][y0 + j] == c) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board, int r, int c)
{
    if(r==9)
        return true;
    if(c==9)
        return solve(board, r+1, 0);
    if(board[r][c]!='.')
        return solve(board, r, c+1);
    for(char i='1';i<='9';i++)
    {
        if(check(board, r, c, i))
        {
            board[r][c]=i;
            if(solve(board, r, c+1))
                return true;
            board[r][c]='.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board, 0, 0);
}



//2nd Question
vector<vector<int>> moves = {{2,1},{2,-1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
bool dfs(vector<vector<int>>& grid,int i,int j,int curr,int n){
    if(curr==n*n-1) return true;
    curr++;
    for(auto dir:moves){
        int nr=i+dir[0],nc=j+dir[1];
        if(nr<0||nc<0||nr>=n||nc>=n) continue;
        if(grid[nr][nc]==curr) {
            return dfs(grid,nr,nc,curr,n);
        }
    }
    return false;
}
bool checkValidGrid(vector<vector<int>>& grid) {
    return dfs(grid,0,0,0,grid.size());
}

int main(){
    cout<<"Lecture 13"<<endl;
    return 0;
}