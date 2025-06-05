#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        string s;
        cin >> s;

        int res = 0;
        // we knwo each time string is of length ->n and want to find the k items 
        // if == k return YES else NO
        
        for (int i = 0; i < n; i++)
        {
          if ( s[i] == s[n-i+1])
          {
            res+=1;
          }
          
        }
        
        

        // Cause we need exactly k so i suppose >k is not acceptable
        if(res > k){
            cout<<res<<"YES"<<endl;
            
        }
        else{
            cout<<res<<"NO"<<endl;
        }
        
    }
    return 0;
}
