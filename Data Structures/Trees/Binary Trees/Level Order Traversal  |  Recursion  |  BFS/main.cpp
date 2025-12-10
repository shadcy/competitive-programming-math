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
    // tf bro always know that the class is private by default
    // ow data will be inaccessible if not changed to public
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void LevelOrderRecursion(Node *root, int level, vector<vector<int>> &res)
{
    // Base case
    if (root == nullptr)
    {
        return;
    }
    // add the new level to the result if needed
    /*
    we have initially res.size() == 0
    why?
    */
    if (res.size() <= level)
    {
        res.push_back({});
    }

    res[level].push_back(root->data);
    LevelOrderRecursion(root->left, level + 1, res);
    LevelOrderRecursion(root->right, level + 1, res);
}
int main()
{
}
