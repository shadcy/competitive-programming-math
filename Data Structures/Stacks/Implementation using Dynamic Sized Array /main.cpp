/*
 * Author: Shreyash (shadcy)
 * Created: 2025-06-05
 */

 // Implementation using Dynamic Sized Array 

 // using vector :  basic implementation

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector <int> s;
  //created a dynamic array

  s.push_back(10);
  s.push_back(20);
  s.push_back(10);
  s.push_back(20);
  s.push_back(10);
  s.push_back(20);
  // and so on to push the elements

  // for pop
  cout<<"Popping "<<s.back() <<" from the stack \n";
  s.pop_back(); // removes the end element

  // to peek the top element of the stack use s.pop_back()

  //to show all the elements in the stack

  while (!s.empty())
  {
    /* code */
    cout<<s.back()<<" ";
    s.pop_back();
  }
  return 0;
}
