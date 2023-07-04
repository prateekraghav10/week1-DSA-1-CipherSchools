#include "bits/stdc++.h"
using namespace std;

void rotate(vector<vector<int>>& matrix) {                      //Brute Force Approach
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> result(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[j][row-i-1] = matrix[i][j];
        }
    }
    matrix=result;
}

void rotate(vector<vector<int>>& matrix) {                      //Optimised Approach
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // vector<vector<int>>::iterator it;
    for(auto &it : matrix){
        reverse(it.begin(),it.end());
    }
}

int main(){
    cout<<"Lecture 4"<<endl;
    return 0;
}