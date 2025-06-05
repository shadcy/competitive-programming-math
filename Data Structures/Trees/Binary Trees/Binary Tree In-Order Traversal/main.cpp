#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    // Right is the pointer pointing to a node, same for left
    Node* right, *left;

    // Constructor
    Node (int key){
       data = key;
       left = nullptr;
       right = nullptr;
    }
};

void InOrderTraversal ( Node *node){
    if( node == nullptr) return;

    // Recursive Algorithm
    InOrderTraversal (node -> left);
    cout<<(node->data)<< " ";
    InOrderTraversal (node -> right);
}

int main() {
    vector<int> root;
    int x;
    while (cin >> x) {
        root.push_back(x);
    }

    if (root.empty()) return 0;

    Node* head = new Node(root[0]);
    queue<Node*> q;
    q.push(head);

    int i = 1;
    while (!q.empty() && i < root.size()) {
        Node* current = q.front();
        q.pop();

        if (i < root.size()) {
            current->left = new Node(root[i++]);
            q.push(current->left);
        }

        if (i < root.size()) {
            current->right = new Node(root[i++]);
            q.push(current->right);
        }
    }

    InOrderTraversal(head);
}

