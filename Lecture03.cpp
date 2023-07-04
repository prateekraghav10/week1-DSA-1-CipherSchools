#include "bits/stdc++.h"
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {                                    //Brute force approach
    int res1 = -1;
    int res2 = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            res1 = i;
            break;
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            res2 = i;
        }
    }
    return {res1,res2};
}

vector<int> searchRange(vector<int>& nums, int target) {                                    //Using inbuild functions
    int start = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int end = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    if(start<nums.size()&&nums[start]==target) return {start,end-1};
    return {-1,-1};
}


int lower_bound(vector<int>& nums,int start,int end, int target){                           //Optimised code by building
    while(start<=end){                                                                      //lower bound function
        int mid = start+(end-start)/2;
        if(nums[mid]<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return start;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int start = lower_bound(nums,0,nums.size()-1,target);
    int end = lower_bound(nums,0,nums.size()-1,target+1);

    if(start<nums.size()&&nums[start]==target) return {start,end-1};
    return {-1,-1};
}


int main(){
    cout<<"Lecture 3"<<endl;
    return 0;
}
