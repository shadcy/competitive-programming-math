/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-08
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
 
    vector<int>temp = {0, 1, 2, 3};
    
    printLL(arraytoLL(temp));

}
