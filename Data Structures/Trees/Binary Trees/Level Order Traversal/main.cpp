/*
 * Author: Shreyash (shadcy)
 * Created: 2025-07-08
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    // now comes the constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
    vector<vector<int>> levelOrder(Node* root){
      vector<vector<int>> res; // to return the answer

      //there are 2 cases 
      //if we have nothing in the root 
      if(root == NULL){return res;}
      //when its not empty // might have in right , left or both
      deque<Node*> _queue; //we are using deque as a queue
      _queue.push_back(root);

      while (!_queue.empty())
      {
        /* as long as _queue not empty */
        int Queuesize = _queue.size();
        vector<int>level;
        for (int i = 0; i < Queuesize; i++)
        {
            Node* node = _queue.front();
            _queue.pop_front(); // imp deque is used so
            //we are using it as a queue --> we have to push to back and
            //pop from the front
            if(node->left != NULL) {_queue.push_back(node->left);}
            if(node->right != NULL) {_queue.push_back(node->right);}
            level.push_back(node->data);
        }
        res.push_back(level);    
      }
      return res;
    }
};

int main()
{
    // level order traversal
}
