/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-07
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 //Implementation of queue ssuing array
 //gonna use vector here

 class Queue
 {
 private:
   //Though the default in class is always private:
   vector <int> q;
 public:
    //we have a vector now
    bool isEmpty(){
        return q.empty();
    }

    //empty , dequeue, enqueue, getfront,

    int dequeue(){
        if(q.empty()){
            cout<<"Queue is empty \n";
            return -1;
        }
        else{
          cout<<"Front is erased \n";
          q.erase(q.begin());
          return 1;
        }
    }

    int enqueue(int data){
        q.push_back(data);
        return 1;
    }


    void getFront(){
        if(!q.empty()){
         cout<<"Front element is"<<q.front()<<endl;
        }
    }
    

    void display(){
     for (auto x: q){
       cout<<x<<" ";
     }
    }
 };
 

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.dequeue();
  q.getFront();
  q.isEmpty();
  q.display();

  //at last we must get queue of size 1 ; 2 3

}
