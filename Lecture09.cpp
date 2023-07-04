#include "bits/stdc++.h"
using namespace std;

int search(vector<int>& nums, int target) {                     //Brute Force approach TC: O(n)
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
}

int search_sorted_array(vector<int>& nums,int start,int end, int target){           //Optimised using recursion
    if(start>end){                                                                  // TC: 0(log(n))
        return -1;
    }
    int mid = (start+end)/2;

    if(nums[mid]==target){
        return mid;
    }

    if(nums[start]<=nums[mid]){
        //left section is sorted haah
        if(target>=nums[start] && target<=nums[mid]){
            return search_sorted_array(nums,start,mid-1,target);
        }
        else{
            return search_sorted_array(nums,mid+1,end,target);
        }
    }
    else{
        if(target>=nums[mid] && target<=nums[end]){
            return search_sorted_array(nums,mid+1,end,target);
        }
        else{
            return search_sorted_array(nums,start,mid-1,target);
        }
    }
}

int search(vector<int>& nums, int target) {
    int result = search_sorted_array(nums,0,nums.size()-1,target);
    return result;

}


int search(vector<int>& nums, int target) {                           //Optimised Iterative approach with TC: O(log(n))
    int start = 0;
    int end = nums.size()-1;

    while(start<=end){
        int mid = start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[start] <= nums[mid]){
            if(target>=nums[start] && target<nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}



int peakIndexInMountainArray(vector<int>& arr) {                            //Brute force approach with TC: O(N)
    for(int i=1;i<arr.size()-1;i++){
        if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){
            return i;
        }
    }
    return -1;
}

int peakIndexInMountainArray(vector<int>& arr) {                            //Optimised approach with TC: O(log(N))
    int start = 1,end = arr.size()-2;

    while(start <=end){
        int mid = start + (end - start)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
            return mid;
        }
        else if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}


vector<vector<int>> threeSum(vector<int>& nums) {                               // Brute force approach with TC: O(N^3)
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort the array

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 1; ++j) {
            // Skip duplicates
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            for (int k = j + 1; k < n; ++k) {
                // Skip duplicates
                if (k > j + 1 && nums[k] == nums[k - 1])
                    continue;

                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }

    return result;
}

vector<vector<int>> threeSum(vector<int>& nums) {                   //Optimise two pointer approach with TC: O(Nlog(N))
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates
        }
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) {
                    j++; // Skip duplicates
                }
                while (j < k && nums[k] == nums[k + 1]) {
                    k--; // Skip duplicates
                }
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
    return result;
}

int main(){
    cout<<"Lecture 9"<<endl;
    cout<<"(Line 4-76) Q1: Search in sorted rotated array Link:- https://leetcode.com/problems/search-in-rotated-sorted-array/ "<<endl;
    cout<<"(Line 80-105) Q2: Peak Index in a Mountain Array Link:- https://leetcode.com/problems/peak-index-in-a-mountain-array/ "<<endl;
    cout<<"(Line 108-167) Q3: 3 Sum problem Link:- https://leetcode.com/problems/3sum/ "<<endl;
    return 0;
}