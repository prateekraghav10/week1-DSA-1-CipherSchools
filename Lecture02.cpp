#include "bits/stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-sorted-array/

void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {            //Brute force approach
    for(int i=0;i<m;i++){
        arr1[n+i]=arr2[i];
    }
    sort(arr1.begin(),arr1.end());
}

void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {            //Optimised Two pointer approach
    vector<int> res(n+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            res[k]=arr1[i];
            i++;k++;
        }else{
            res[k]=arr2[j];
            j++;k++;
        }
    }
    while(i<n){
        res[k]=arr1[i];
        i++;k++;
    }
    while(j<m){
        res[k]=arr2[j];
        j++;k++;
    }
    arr1=res;
}

int main(){
    cout<<"Lecture 2"<<endl;
    return 0;
}