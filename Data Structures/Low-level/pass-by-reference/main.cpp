/*
 * Author: Shreyash (shadcy)
 * Created: 2026-06-26
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//func with pass by ref
void increment_wref(int &x){
  x++; //x is incremented by 1
}

//func with pass by val
int increment_wval(int x){
    x++;
    return x;
}


int main() {
 //code for pass by ref and pass by copy comparison
 int a;
 cout<<"Enter the number you want to increment:";
 cin>>a;
 cout<<"\n";
 
// for pass by ref
//  increment_wref(a);
//  cout<<a<<endl;

//for pass by val
 cout<<increment_wval(a);


}
