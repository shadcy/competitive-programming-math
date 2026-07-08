/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-05
 */

#include <iostream>
using namespace std;
int factorial(int n){
    //base case
    if(n <= 0){
        return 1;
    }

    //here comes the recursive step
    //smaller answer = func (smaller problem)
    return (n * factorial(n-1) );

}
int main() {
  int n;
  cin>>n;
  cout<<factorial(n)<<endl;
 //program for calculation of the factorial using recursion
}
