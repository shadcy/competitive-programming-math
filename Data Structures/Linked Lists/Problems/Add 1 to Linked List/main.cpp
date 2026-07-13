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
Node* addX(Node* head,  int X){
    //Here the X is only a digit ranging from 0 to 9
    //This problem is taken from the lc section, as its a premuim we are solving it here
    Node* temp = head;
    int sum = X;
    int carry = 0;
    Node* newHead = new Node(-1);
    Node* res = newHead;
    while(temp!=nullptr){
      sum += carry;
      sum += temp->data; 

      
       newHead->next = new Node(sum%10);
       carry = sum/10;
  
       sum = 0;
       temp = temp->next;
       newHead=newHead->next;
    }
    if(carry){
        newHead->next = new Node(1);
    }
    return res->next;
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
    vector<int>temp = {9, 9};
    Node* newLL = arraytoLL(temp);
    printLL(addX(newLL,1));

}
