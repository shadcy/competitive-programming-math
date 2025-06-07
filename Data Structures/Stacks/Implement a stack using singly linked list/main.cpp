/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-05
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//structure of node
struct Node {
    //can do this with the class also
    //default struct is -> public
    //meanwhile in class we have to define public: private:
    int data;
    Node* next;

    //now need constructor to construct the node each time we call a node
    Node(int d){
        data = d;
        next = nullptr;

    }
};

struct Stack{
    Node* head;
    //constructor to initialize the stack
    Stack(){
        head = nullptr;
    }

    bool empty(){
        return head==nullptr;
    }

    void push(int val){
        Node* new_node = new Node(val);
        // now we are adding everythin to the top of the head
        // so that our complexity will be O(1) and for deleting O(1)
        // meanwhiledeleting the node gonna need O(n) if we delete the element in the end
        // as it gonna need traversal
        new_node->next = head;
        head = new_node;

    }

    void pop(){
        // to simply put nothing to print if empty
          if (empty()) {
            // stack underflow happens when we have no elements and 
            //we are trying to pop the element
            cout << "Stack Underflow\n";
            return;
            // using return; will end the function and gonna just return Stack underflow message
        }
        //Why temp is needed?
        //Moving the head pointer to the next node in the stack.

        // But you lose the reference to the old head node completely.

        // This means you can no longer delete it — which leads to a memory leak.

        Node* temp = head;
        head = head->next;
        delete temp;

            // This ensures:

            // You preserve a pointer to the node you want to delete.

            // You safely update the head.

            // You free memory properly.


    }


    int peek(){
        //out the element on the top
        // just print the head?
        if(!empty()){
            return head->data;
        }
        //what if is empty?
        else{
            cout<<"Stack is empty \n";
            return INT16_MIN;
        }
    }

};

int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    cout << "Top element is " << st.peek() << endl;

    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    cout << "Top element is " << st.peek() << endl;

    return 0;

    //nice it worked
}