#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n]; 
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr, arr + n);
        
        bool hasDuplicate = false;
        for(int i = 0; i < n-1; i++) {
            if(arr[i+1] == arr[i]) {
                cout << "no" << endl;
                hasDuplicate = true;
                break;
            }
        }
        
        if(!hasDuplicate) {
            cout << "yes" << endl;
        }
    }
    return 0;
}