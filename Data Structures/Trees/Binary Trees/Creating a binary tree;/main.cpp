#include <iostream>
#include <bitset>
using namespace std;

// Create a new data type
struct Node {
    int data;
    Node *left, *right;
    
    // Constructor
    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};


int main() {
  // Creating  a binary tree
  Node *root = new Node(2);
  Node *second = new Node(3);
  Node *third = new Node(4);
  Node *fourth = new Node(5);


  // connecting a tree
  root->left = second;
  root->right = third;
  second->left = fourth;

  //Connected the tree, this is complete implementation of
  // trees data structure in cpp

  //yipee
  
  
}
