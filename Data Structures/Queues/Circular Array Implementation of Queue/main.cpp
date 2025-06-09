/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-07
 * Template: Competitive Programming
 */

#include <bits/stdc++.h>
using namespace std;

class Queue{
 int* arr;
 int front, size;
 int cap; //This is capacity of array
 //can say queue too

 public:
 //construct and init the queue
    Queue(int capacity){
        arr = new int[capacity];
        //In simple terms : "Creates a new array of integers with c elements, and store its starting address in the pointer arr"
        //This gonna create arr = {? ? ? ? ------ ? x capacity}
        cap = capacity;
        front = 0;
        size = 0;
    }

    int getFront(){
        // Queue is empty
            if (size == 0) 
                return -1; 
            return arr[front];
    }


     // Get the rear element
    int getRear() {
      
        // Queue is empty
        if (size == 0) 
            return -1; 
        int rear = (front + size - 1) % cap;
        return arr[rear];
    }

        // Insert an element at the rear
    void enqueue(int x) {
      
        // Queue is full
        if (size == cap) 
            return; 
        int rear = (front + size) % cap;
        arr[rear] = x;
        size++;
    }

    // Remove an element from the front
    int dequeue() {
      
        // Queue is empty
        if (size == 0) 
            return -1;
        int res = arr[front];
        front = (front + 1) % cap;
        size--;
        return res;
    }


};

void solve() {
    // Your solution here
    //Implementing queue usign circular array

    //in circular array last element of array is connected to the front
    //with this statement we can see we;ll require a array pointing to an integer
    //say int* arr; array pointing to an integer

       Queue q(4);
    q.enqueue(10);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(20);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(50);
    cout << q.getFront() << " " << q.getRear() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}


