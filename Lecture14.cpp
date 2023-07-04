#include "bits/stdc++.h"
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//1st Question
ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
    ListNode* result;
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    if(list1->val < list2->val){
        result=list1;
        result->next=mergeTwoLists(list1->next,list2);
    }
    else{
        result=list2;
        result->next=mergeTwoLists(list1,list2->next);
    }
    return result;
}


//2nd Question
ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
    ListNode* result;
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    if(list1->val < list2->val){
        result=list1;
        result->next = mergeTwoLists(list1->next,list2);
    }
    else{
        result=list2;
        result->next = mergeTwoLists(list1,list2->next);
    }
    return result;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *mergelist = NULL;
    for (int i = 0; i < lists.size(); i++) {
        mergelist = mergeTwoLists(mergelist, lists[i]);
    }
    return mergelist;
}


//3rd Question
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* prev=NULL;
    ListNode* curr=head;

    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    cout<<"Lecture 14"<<endl;
    return 0;
}