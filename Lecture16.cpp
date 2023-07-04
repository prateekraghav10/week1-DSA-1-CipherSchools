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
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    while(temp && temp->next){
        if(temp->val == temp->next->val){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}



//2nd Question
int length(ListNode* head){
    ListNode* temp=head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==0){
        return head;
    }
    ListNode* temp=head;
    int len=length(head);
    while(temp->next){
        temp=temp->next;
    }
    temp->next = head;
    k=k%len;
    k=len-k;
    while(k--){
        temp=temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}


//3rd Question
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {                   //Iterative way
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1==NULL && l2==NULL) return NULL;
    ListNode* res = new ListNode(0);
    ListNode* head = res;
    int carry=0;
    while(l1 && l2){
        int sum=l1->val + l2->val + carry;
        carry = sum/10;
        res->next = new ListNode(sum%10);
        res = res->next;
        l1=l1->next;
        l2=l2->next;
    }

    while(l1){
        int sum=l1->val + carry;
        carry = sum/10;
        res->next = new ListNode(sum%10);
        res = res->next;
        l1=l1->next;
    }
    while(l2){
        int sum = l2->val + carry;
        carry = sum/10;
        res->next = new ListNode(sum%10);
        res = res->next;
        l2=l2->next;
    }

    if(carry){
        res->next = new ListNode(carry);
    }
    return head->next;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {               //Recursive way
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1==NULL && l2==NULL) return NULL;
    int sum = l1->val + l2->val;
    ListNode* res = new ListNode(sum%10);
    res->next = addTwoNumbers(l1->next,l2->next);
    if(sum>=10){
        res->next = addTwoNumbers(res->next,new ListNode(1));
    }
    return res;
}
int main(){
    cout<<"Lecture 16"<<endl;
    return 0;
}