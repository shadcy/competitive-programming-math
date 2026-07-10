
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *arraytoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    temp->next = nullptr;

    return head;
}

void printLL(const Node *head)
{
    const Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
int getPos(Node* head, Node* targetNode){
    Node* temp = head;
    int count=1;
    while(temp != targetNode){
         count++;
         temp=temp->next;
    }
    return count;
}

bool detectCycle(Node *head)
{
    // This func is to detect the cycles in the linked list
    // First method is to have a algorithm with O(n) space and O(n) time complexity
    // Second is by using the Floyd's cycle detections

    // First with the visited set array
    set<Node *> visited;
    Node *temp = head;
    while (temp != nullptr) // I assume this incase of cycles doesnt make sense; its anyways always true
    {
        if (visited.count(temp))
        {
            cout << "Cycle detected at position:" << getPos(head, temp)<< "\n";
            return true;
        }
        else
        {
            visited.insert(temp);
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> example = {1, 2, 1, 2, 5, 6};
    Node *head = arraytoLL(example);
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // Make the last node point back to the third node
    tail->next = head->next->next->next;
    cout << endl;
    (detectCycle(head)) ? cout << "True" : cout << "False";
    cout << endl;
}
