/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-05
 */

#include <iostream>
using namespace std;
//program to print fibonacci of n numbers
//fibonacci seq : 1, 1, 2, 3, 5, 8, 13, .....

int fibonacci(int n){
    //base case 
    if(n<2){
        return n;
    }

    //recursive step
    // cout<<fibonacci(n)<<" ";

    //combine
    //assuming lof(leap of faith) is algo works
    //fib of idx 3 = fib of idx 2 + fib of idx 1
    return (fibonacci(n-1) + fibonacci(n-2));
}
int main() {

  cout<<fibonacci(7);
}
