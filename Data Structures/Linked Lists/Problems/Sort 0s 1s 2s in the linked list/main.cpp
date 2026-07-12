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

Node *reverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *curr = head;
    Node *temp = nullptr;
    while (curr != nullptr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        // swapped both the pointers
        curr = curr->prev;
    }

    return temp->prev;
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

Node *sortLL(Node *head)
{
    // its supposed to be linked list and not dll so keep that in mind,
    //
    Node *head0 = new Node(-1);
    Node *zeroHead = head0;
    Node *head1 = new Node(-1);
    Node *oneHead = head1;
    Node *head2 = new Node(-1);
    Node *twoHead = head2;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            head0->next = new Node(temp->data);
            head0 = head0->next;
        }
        else if (temp->data == 1)
        {
            head1->next = new Node(temp->data);
            head1 = head1->next;
        }
        else
        {
            head2->next = new Node(temp->data);
            head2 = head2->next;
            // assuming its guranteed the data is only in 1, 2, and 0s
        }
        temp = temp->next;
    }
    // Edge cases?
    // what if there are no ones or zeros in the linked list
    if (zeroHead->next == nullptr)
    {
        if(oneHead->next == nullptr){
            return twoHead->next;
        }
        else{
            //oneHead exists
            head1->next = twoHead->next;
            return oneHead->next;
        }
    }
    else{
        //zero exists
        if(oneHead -> next == nullptr){
            //if oneHead dont exist
            head0->next = twoHead->next;
        }
        else{
            //oneHead exists
            head0->next = oneHead->next;
            head1->next = twoHead->next;
        }
    }
    // return the zero head
    return zeroHead->next;
    // rule of thumb;
    delete zeroHead;
    delete oneHead;
    delete twoHead;  
}

int main()
{
    vector<int> a = { 1, 2, 1, 2, 0, 0 };
    Node *example = arraytoDll(a);
    cout << "\n";
    printDLL(example);
    example = sortLL(example);

    cout << "\n";
    printDLL(example);
    cout << "\n";
}
