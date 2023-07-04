#include "bits/stdc++.h"
using namespace std;

//https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left=0;
    int right = matrix[0].size()-1;
    int top=0;
    int bottom = matrix.size()-1;
    int index=0;
    vector<int> res((right+1)*(bottom+1));

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res[index]=matrix[top][i];
            index++;
        }
        top++;

        for(int i=top;i<=bottom;i++){
            res[index]=matrix[i][right];
            index++;
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                res[index]=matrix[bottom][i];
                index++;
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res[index]=matrix[i][left];
                index++;
            }
            left++;
        }
    }
    return res;
}

int main(){
    cout<<"Lecture 5"<<endl;
    return 0;
}