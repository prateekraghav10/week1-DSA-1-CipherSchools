#include "bits/stdc++.h"
using namespace std;

//https://leetcode.com/problems/trapping-rain-water/

int trap(vector<int>& height) {                         //two pointer approach (using lmax,rmax)
    int n = height.size();                                         //T.C: O(n+n+n)=O(3n)
    vector<int> lmax(n);
    vector<int> rmax(n);

    lmax[0]= height[0];
    for(int i=1;i<n;i++){
        lmax[i] = max(lmax[i-1],height[i]);
    }

    rmax[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i] = max(rmax[i+1],height[i]);
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=((min(lmax[i],rmax[i])-height[i]));
    }
    return sum;
}

int trap(vector<int>& height) {                         //Little optimise using 2 loops instead of 3 loops
    int n = height.size();                                              ////T.C: O(n+n)=O(2n)
    vector<int> lmax(n);
    vector<int> rmax(n);

    lmax[0]= height[0];
    rmax[n-1] = height[n-1];
    for(int i=1;i<n;i++){
        lmax[i] = max(lmax[i-1],height[i]);
        rmax[n-i-1] = max(rmax[n-i],height[n-i-1]);
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=((min(lmax[i],rmax[i])-height[i]));
    }
    return sum;
}


int main(){
    cout<<"Lecture 6"<<endl;
    return 0;
}