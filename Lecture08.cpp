#include "bits/stdc++.h"
using namespace std;

void sortColors(vector<int>& nums) {                                    //Brute force approach with NO extra space
    int zero=0,one=0,two=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            zero++;
        }
        if(nums[i]==1){
            one++;
        }
        if(nums[i]==2){
            two++;
        }
    }
    for(int i=0;i<zero;i++){
        nums[i]=0;
    }
    for(int i=zero;i<one+zero;i++){
        nums[i]=1;
    }
    for(int i=zero+one;i<nums.size();i++){
        nums[i]=2;
    }
    cout<<zero<<one<<two<<endl;
}


void sortColors(vector<int>& nums) {                                    //Optimise approach with also NO extra space
    int zero=0,one=0,two=nums.size()-1;
    while(one<=two){
        if(nums[one]==0){
            swap(nums[zero],nums[one]);
            zero++;
            one++;
        }
        else if(nums[one]==1){
            one++;
        }
        else{
            swap(nums[one],nums[two]);
            two--;
        }
    }
}


void sortColors(vector<int>& nums) {
    sort(nums.begin(),nums.end());                          //Using inbuilt function with T.C. :- O(nlogn)
}


void setZeroes(vector<vector<int>>& vec) {                          //Brute Force approach with TC: O(n*m) & SC: (n+m)
    int n = vec.size();
    int m = vec[0].size();
    vector<int> v1(n,1);
    vector<int> v2(m,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==0){
                v1[i] = 0;
                v2[j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v1[i]==0 || v2[j]==0){
                vec[i][j]=0;
            }
        }
    }
}


void setZeroes(vector<vector<int>>& matrix) {                           //Optimised approach with TC: O(n*m) & SC: (1)
    int n = matrix.size();
    int m = matrix[0].size();
    bool flag1 = false, flag2 = false;
    for(int i=0; i<n; i++){
        if(matrix[i][0] == 0){
            flag1 = true;
        }
    }
    for(int j=0; j<m; j++){
        if(matrix[0][j] == 0){
            flag2 = true;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(flag1 == true){
        for(int i=0; i<n; i++){
            matrix[i][0] = 0;
        }
    }
    if(flag2 == true){
        for(int j=0; j<m; j++){
            matrix[0][j] = 0;
        }
    }
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {                    //Brute Force approach TC:  O(N*M)
    for(auto row:matrix){
        for(auto col:row){
            if(col==target){
                return true;
            }
        }
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {                    //Optimised approach TC:  O(N+M)
    int row = 0;
    int col = matrix[0].size()-1;

    while(row<matrix.size() && col>=0){
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
    return false;
}

int main(){
    cout<<"Lectrue 8"<<endl;
    cout<<"(Line 4-51) Q1: Sort Colors Link:- https://leetcode.com/problems/sort-colors/ "<<endl;
    cout<<"(Line 54-115) Q2: Set Matrix Zero Link:- https://leetcode.com/problems/set-matrix-zeroes/ "<<endl;
    cout<<"(Line 118-146) Q3: Search a 2D matrix Link:- https://leetcode.com/problems/search-a-2d-matrix/ "<<endl;
    return 0;
}