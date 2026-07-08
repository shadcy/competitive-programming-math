/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-05
 */

#include <iostream>
using namespace std;
//program to calculate sum of first n numbers

int sum(int n){
    //base case 
    if(n <= 0){
        return 0;
    }

    return n + sum(n-1);
}
int main() {

 int n;
 cin>>n;


 cout<<sum(n)<<endl;

}
