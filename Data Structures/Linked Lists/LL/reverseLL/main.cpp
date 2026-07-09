/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-09
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* reverseLL(Node* head){
    //Edge cases for no element and only one element/ more precisely node 
    if(head == nullptr || head->next == nullptr) return head;
    //This will be making an input smaller
    Node* newHead = reverseLL(head->next);
    head->next->next=head;
    head->next=nullptr;

    return newHead;
}

Node* arraytoLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
       temp->next = new Node(arr[i]);
       temp=temp->next;
    }
    temp->next=nullptr;
    
    return head;
}

void printLL(const Node* head){
 const Node* temp = head;
 while(temp!= nullptr){
    cout<<temp->data<<"->";
    temp=temp->next;
 }
 cout<<"NULL";
}
int main() {
 vector<int> example = {1, 2, 3, 4, 5, 6};
 Node* temp = arraytoLL(example);
 printLL(temp);
 cout<<endl;
 printLL(reverseLL(temp));
  cout<<endl;
}
