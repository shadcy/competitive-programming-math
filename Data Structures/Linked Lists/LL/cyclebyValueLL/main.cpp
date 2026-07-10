
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

bool detectCycle(Node *head)
{
    // This func is to detect the cycles in the linked list
    // First method is to have a algorithm with O(n) space and O(n) time complexity
    // Second is by using the Floyd's cycle detections

    // First with the visited set array
    set<int> visited;
    Node *temp = head;
    int count = 1;
    while (temp != nullptr)
    {
        if (visited.count(temp->data))
        {
            cout << "Cycle detected at position:"<<count<<"\n";
            return true;
        }
        else
        {
            count++; // move to the next
            visited.insert(temp->data);
        }
      temp = temp->next;
    }
}

int main()
{
    vector<int> example = {1, 2, 1, 2, 5, 6};
    Node *temp = arraytoLL(example);
    printLL(temp);
    cout << endl;
    (detectCycle(temp)) ? cout << "True" : cout << "False";
    cout << endl;
}
