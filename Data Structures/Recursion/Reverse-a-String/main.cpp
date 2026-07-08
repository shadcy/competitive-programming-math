/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-05
 */

#include <iostream>
using namespace std;
// reverse a string using recursion
string revstring(string s, int i){
    //s is the string itself, and i is the tracker
   if(i<0){
    return ""; //stop asap
   }
    cout<<s[i];
    return revstring(s, i-1);
}
int main() {

  string s;
  cin>>s;

  revstring(s, s.size());
  return 0;
}
