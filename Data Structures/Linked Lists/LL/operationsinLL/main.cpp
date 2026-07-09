/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-08
 */

/**
 * @brief This page uses the code from @cite /LL/arraytoLL
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// creating the user defined data type

class Node
{
    // members are private by default in classes, need to be public
public:
    int data;
    Node *next; // pointer pointing to the next node
    // constructor
    Node()
    {
        data = 0;
        next = nullptr;
    } // default one
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    Node(int val, Node *nextptr)
    {
        data = val;
        next = nextptr;
    }
    // here we have covered all the cases which, person can create an obj ig
};

Node *arraytoLL(vector<int> &arr)
{
    if (arr.empty())
    {
        return 0;
    }
    // this function must convert the arr to linked list
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        /* code */
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

class Operation
{
    // this class does is to give access to diff operations performed on the LL
    // as the node class is all public we dont need to worry about access modifiers
public:
    // For special cases, we might need the size function to get the size of a LL
    // UTILITY MEMBERS
    int sizeofLL(const Node *head)
    {
        const Node *temp = head;
        int size = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
    void printLL(Node *head)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            /* code */
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
    Node *removeHead(Node *head)
    {
        /**
         * @brief removes head from the LL
         * @param head returns the address of the head node
         * @result returns address of the new head
         */

        /*
        //This has time complexity of O(n) better implementation is given below, which is currently we are using
          if(sizeofLL(head) > 0){
           // To avoid memory leak we need to store the head to temp node and delete it afterwards accordingly.
           Node* temp = head;
           head=head->next;
           delete temp;
           return head;
          }
          else{
            cout<<"Nothing to delete";
            return nullptr;
          }
        */

        if (head == nullptr)
        {
            cout << "Nothing to delete" << endl;
            return nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
    }
    Node *removeTail(Node *head)
    {
        // the complexity of this is going to be O(n) w/o tail pointer
        /**
         * @details we are going to traverse to the complete untill nullptr and create a temp
         * store the tail, and delete the node safely
         */

        /**
         * @def if there is no node return null pointer
         */
        if (head == nullptr)
        {
            return nullptr;
        }

        /**
         * @def if there is only one node, we need to delete that and return the nullptr
         */
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }

        /**
         * @def if there are more than one head, need to follow the scheme below
         */
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
    Node *removeNode(Node *head, int pos)
    {
        int currSize = sizeofLL(head);
        if (pos < 1 || pos > currSize)
        {
            cout << "Invalid Position\n";
            return head;
        }
        if (pos == 1)
            return removeHead(head);
        if (pos == currSize)
            return removeTail(head);
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        return head;
    }

    Node *addHead(Node *head, int value)
    {
        // Edge cases?
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *addTail(Node *head, int value)
    {
        if(head == nullptr){
           Node* newNode = new Node(value);
           return newNode;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        temp->next = newNode;
        newNode->next = nullptr;
        return head;
    }
    Node *addNode(Node* head, int value, int pos) {
        //general purpose function to add nodes covering the edge cases for adding at the head and adding at the tail
        // Edge case: Boundry condition
        //To save some more cycles from calling the same function
        int currSize = sizeofLL(head);
        if(pos < 1 && pos > currSize+1){
            cout<<"Invalid Position \n";
            return head;
        }
        //Edge case: No node; we create a new pointer and 
        if(head == nullptr){
            Node* newNode = new Node(value);
            return newNode;
        }
        //Edge case: if pos == sizeofLL + 1 mean we are adding at the tail so
        if(pos == (currSize+1)){
            head = addTail(head, value);
            return head;
        }
        //Edge case: if pos == 1 its a addition to head
        if(pos == 1){
           head = addHead(head, value);
           return head;
        }
        //Otherwise
        Node* temp = head;
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        //we are at pos-1
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next= newNode;

        
        return head;
    }

    void deleteLL(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            /* code */
            Node *nodetoDelete = temp;
            temp = temp->next;
            delete nodetoDelete;
            nodetoDelete = nullptr;
        }
    }
};

int main()
{
    vector<int> exampleArray = {1, 3, 4, 5};
    Operation ops;
    Node *exampleLL = arraytoLL(exampleArray);
    ops.printLL(exampleLL);
    cout << "Size : " << ops.sizeofLL(exampleLL) << endl;
    exampleLL = ops.addNode(exampleLL,2, 2);
    ops.printLL(exampleLL);
}
