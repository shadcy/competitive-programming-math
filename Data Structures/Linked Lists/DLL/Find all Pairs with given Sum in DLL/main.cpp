/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-11
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node for our doubly Linked List
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
// We now have our user-defined data type ready
// which is a node, one points to the next pointer and one points to the previous pointer;
Node *arraytoDll(const vector<int> &arr)
{
    // The pass by reference really make sense here when we have a very huge array.
    // For larger objects the pass by vaue changes the complexity from O(1) to O(N).
    // For smaller primitives, the diff is negligible.

    // Edge cases: case 1: if no element in a array
    if (arr.size() == 0)
    {
        return nullptr;
    }
    else if (arr.size() == 1)
    {
        Node *newNode = new Node(arr[0]);
        return newNode;
    }
    else
    {
        // This should work for == 3 or more
        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *curr = new Node(arr[i]);
            prev->next = curr;
            curr->prev = prev;

            prev = curr;
        }
        return head;
    }
}
void printDLL(const Node *head)
{
    cout << "NULL";
    cout << "<-";
    const Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
/*
Find the pairs with the given sum in DLL.
example sum = 5;
DLL : 1<->2<->3<->4<->9
Out : (1, 4) and (2, 3)

Constraints, given a dll is sorted, and valid.
When given that the DLL, or array is in a sorted manner, we have options to solve this question in <=O(n^2) and possibly log(n) time.
giving tail of dll = right
head of add = left
if(right + left > sum){
   right = right->prev;
}
else if(right + left < sum){
   left = left->next;
}
else if(right+left == sum){
 return (left, right).
}
else if(right == left){
   tells you if there is only one element of size sum. return this element as is.
}
else{
   nothing found. can return -1 in such cases.
}
*/
// we need to find the tail of the dll first
Node *findTail(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp;
}
vector<pair<int, int>> findPairs(Node *head, int k)
{ // here k is a sum required
    Node *left = head;
    Node *right = findTail(head);
    vector<pair<int, int>> res;
    while (left->data < right->data)
    {
        /*
        incase left->data == right->data, we can even use this case, inorder to solve if returning only one element is valid
        */
        if ((left->data + right->data) == k)
        {
            res.push_back({left->data, right->data});
            // fuck my fix
            left = left->next;
            right = right->prev;
        }
        else if ((left->data + right->data) < k)
        {
            left = left->next;
        }
        else if ((left->data + right->data) > k)
        {
            right = right->prev;
        }
    }
    return res;
}
int main()
{
    vector<int> a = {1, 2, 4, 5, 6, 8};
    Node *example = arraytoDll(a);
    cout << "\n";
    printDLL(example);
    cout << "\n";
    vector<pair<int, int>> pairs = findPairs(example, 6);
    cout << "Pairs with sum 6: ";
    for (const auto &pair : pairs)
    {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << "\n";
}
