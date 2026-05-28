#include <iostream>
#include <algorithm>
using namespace std;
int main() {
 int t;
 cin>>t;
 while(t--){
    int arr[3]; // Array to store three numbers
    // a[0], b[1], c[2]
    // Taking input for three numbers
    cin >> arr[0] >> arr[1] >> arr[2];
    // Sorting the numbers
    sort(arr, arr + 3);
    if(arr[2] == arr[1] + arr[0]){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
 }
}
