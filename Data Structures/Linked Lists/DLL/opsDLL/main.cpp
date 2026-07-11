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

Node *deleteHead(Node *head)
{
    // base case:
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *prev = head;

    head = head->next;
    prev->next = nullptr;
    head->prev = nullptr;

    delete prev;
    return head;
}

void printDLL(const Node *head)
{
    cout << "NULL";
    cout << "<-";
    const Node *temp = head;
    while (temp)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL";
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *example = arraytoDll(a);
    cout << "\n";
    printDLL(example);
    example = deleteHead(example);
    cout << "\n";
    printDLL(example);
    cout << "\n";
}
