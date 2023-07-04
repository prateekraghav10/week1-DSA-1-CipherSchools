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
bool hasCycle(ListNode *head) {
    ListNode* fast= head;
    ListNode* slow= head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}



//2nd Question
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* fast = headA;
    ListNode* slow = headB;

    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            slow=headA;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
        }

    }
}

int main(){
    cout<<"Lecture 15"<<endl;
    return 0;
}