#include "bits/stdc++.h"
using namespace std;

//1st Question
int alluniquePaths(int row,int col,int m,int n,vector<vector<int>> &dp){
    if(row>=m || col>=n){
        return 0;
    }
    if(row==(m-1) && col==(n-1)){
        return 1;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int down = alluniquePaths(row+1,col,m,n,dp);
    int right = alluniquePaths(row,col+1,m,n,dp);

    dp[row][col]=(right+down);
    return dp[row][col];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return alluniquePaths(0,0,m,n,dp);
}



//2nd Question
int alluniquePathsWithObstacles(vector<vector<int>>& matrix,int row,int col,int m,int n,vector<vector<int>> &dp){
    if(row>=m || col>=n){
        return 0;
    }
    if(row==(m-1) && col==(n-1) && matrix[row][col]!=1){
        return 1;
    }
    if(matrix[row][col]==1){
        return 0;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int down = alluniquePathsWithObstacles(matrix,row+1,col,m,n,dp);
    int right = alluniquePathsWithObstacles(matrix,row,col+1,m,n,dp);

    dp[row][col]=(down+right);
    return dp[row][col];
}

int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return alluniquePathsWithObstacles(matrix,0,0,m,n,dp);
}



//3rd Question
int alluniquePathsIII(vector<vector<int>>& grid,int row,int col,int destx,int desty,int cnt,vector<vector<bool>> &visited){
    if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==-1){
        return 0;
    }
    if(row==destx && col==desty){
        return cnt==0 ? 1 : 0;
    }
    if(visited[row][col]){
        return 0;
    }

    visited[row][col] = true;
    int top = alluniquePathsIII(grid,row-1,col,destx,desty,cnt-1,visited);
    int dowm = alluniquePathsIII(grid,row+1,col,destx,desty,cnt-1,visited);
    int left = alluniquePathsIII(grid,row,col-1,destx,desty,cnt-1,visited);
    int right = alluniquePathsIII(grid,row,col+1,destx,desty,cnt-1,visited);
    visited[row][col] = false;

    return (top+dowm+left+right);
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    int cnt=0;
    int row,col,destx,desty;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                cnt++;
            }
            if(grid[i][j]==1){
                row=i;
                col=j;
            }
            if(grid[i][j]==2){
                destx=i;
                desty=j;
            }
        }
    }
    return  alluniquePathsIII(grid,row,col,destx,desty,cnt+1,visited);
}



//4th Question
bool isSafe(vector<vector<bool>>& chess, int x, int y, int N) {
    for (int i = 0; i < x; i++) {
        if (chess[i][y])
            return false;
    }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j])
            return false;
    }
    for (int i = x, j = y; i >= 0 && j < N; i--, j++) {
        if (chess[i][j])
            return false;
    }
    return true;
}

void solveNQueensHelper(vector<vector<bool>>& chess, int row, int N, vector<vector<string>>& result) {
    if (row == N) {
        vector<string> solution;
        for (int i = 0; i < N; i++) {
            string rowStr = "";
            for (int j = 0; j < N; j++) {
                if (chess[i][j])
                    rowStr += 'Q';
                else
                    rowStr += '.';
            }
            solution.push_back(rowStr);
        }
        result.push_back(solution);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(chess, row, col, N)) {
            chess[row][col] = true;
            solveNQueensHelper(chess, row + 1, N, result);
            chess[row][col] = false;  // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<bool>> chess(n, vector<bool>(n, false));
    vector<vector<string>> result;
    solveNQueensHelper(chess, 0, n, result);
    return result;
}

int main(){
    cout<<"Lecture 11"<<endl;
    cout<<"Done 2 & 3 extra for clear understanding of the concept "<<endl;
    return 0;
}