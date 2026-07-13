/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-13
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//creating the user defined data type

class Node {
    //members are private by default in classes, need to be public 
public:
  int data;
  Node* next; // pointer pointing to the next node

  //constructor
  Node(){
    data = 0;
    next = nullptr;
  } //default one
  Node(int val){
    data = val;
    next = nullptr;
  }
  Node(int val,Node* nextptr){
    data = val;
    next = nextptr;
  }
 //here we have covered all the cases which, person can create an obj ig
};

//this piece of shit is using the 
Node* arraytoLL (vector<int>& arr){
  //this function must convert the arr to linked list
  Node* head = new Node(arr[0]);
  Node* curr = head;
  for (int i = 1; i < arr.size(); i++)
  {
    /* code */
    Node* temp = new Node(arr[i]);
    curr->next = temp;
    curr=temp;
  }
  return head;
}

Node* reverseLLIterative(Node* head){
    if(head==nullptr || head->next==nullptr){
       return head;
    }
    //Which means we have >= 2 elements after the above base case
      Node* prev = head;
      Node* curr = head->next;
      Node* temp = nullptr;
      while(curr != nullptr){
        prev->next=temp;
        temp=prev;
        prev=curr;
        curr=curr->next;
      }
      //last element remaining
      prev->next=temp;
      return prev;
}

void printLL(Node* head){ 
 Node* curr = head;
 while (curr != nullptr)
 {
    /* code */
     cout<<curr->data<<"->";
     curr=curr->next;
 }
 cout<<"NULL"<<endl;
}

int main() {
    //our goal is to create a function which adds 1 to LL
    // suppose it was 1 -> 2 -> 3 then we add 1 to this LL
    //and get 2 -> 2 -> 3
    vector<int>temp = {0};
    Node* newLL = arraytoLL(temp);
    printLL(reverseLLIterative(newLL));

}
