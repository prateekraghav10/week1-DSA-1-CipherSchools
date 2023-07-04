#include "bits/stdc++.h"
using namespace std;

/*
 * All Sorting Algorithms
 * 1) Bubble Sort
 * 2) Selection Sort
 * 3) Insertion Sort
 * 4) Merge Sort    (Divide and Conquer Algorithm)
 * 5) Quick Sort    (Divide and Conquer Algorithm)
 */

void bubble_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

void insertion_sort(vector<int> &arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int j=i;
        while (j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}


void merge(vector<int> &arr,int start,int mid, int end){
    vector<int> arr1(arr.begin()+start,arr.begin()+mid+1);
    vector<int> arr2(arr.begin()+mid+1,arr.begin()+end);

    int i=0,j=0,k=start;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;k++;
        }
        else{
            arr[k]=arr2[j];
            j++;k++;
        }
    }
    while(i<arr1.size()){
        arr[k]=arr1[i];
        i++;k++;
    }
    while(j<arr2.size()){
        arr[k]=arr2[j];
        j++;k++;
    }
}

void merge_sort(vector<int> &arr,int start,int end){
    int n = arr.size();
    if(start>=end)   return;

    int mid = start+(end-start)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);

    merge(arr,start,mid,end);
}


int partition(vector<int> &arr,int start,int end){
    int piv = arr[end];
    int i = start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<piv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return (i+1);
}

void quick_sort(vector<int> &arr,int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);

        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}


void print(vector<int> arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Lecture 7"<<endl;
    vector<int> arr = {3,7,4,1,8,2,6,9};
//    bubble_sort(arr);
//    selection_sort(arr);
//    insertion_sort(arr);
//    merge_sort(arr,0,8);
    quick_sort(arr,0,8);
    print(arr);
    return 0;
}