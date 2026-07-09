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

// this piece of shit is using the
Node *arraytoLL(vector<int> &arr)
{
    if(arr.empty()){
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
// hi lol

class Operation
{
    // this class does is to give access to diff operations performed on the LL
    // as the node class is all public we dont need to worry about access modifiers

public:
    // For special cases, we might need the size function to get the size of a LL
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

    void deleteLL(Node* head){
        Node* temp = head;
        while (temp != nullptr)
        {
            /* code */
        Node* nodetoDelete = temp; 
        temp=temp->next;
        delete nodetoDelete;
        nodetoDelete = nullptr;
        }
        
    }
};

int main()
{

    vector<int> exampleArray = {0, 1, 2, 3};
    Operation ops;
    Node *exampleLL = arraytoLL(exampleArray);
    printLL(exampleLL);
    cout << "Size : " << ops.sizeofLL(exampleLL) << endl;
    // exampleLL = ops.removeHead(exampleLL);
    exampleLL = ops.removeTail(exampleLL);
    printLL(exampleLL);
}
