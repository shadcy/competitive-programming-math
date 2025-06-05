#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--)
  {
      int n;
      cin>>n;
      int matches[n];
      string res = "NO";
      // Initialize the array to take the input
      for (int i = 0; i < n; i++)
      // For players from 1 - (n-1)
      {
        /* code */
        cin>>matches[i];
      }


      for (int i = 0; i < n-1; i++)
      // For players from 1 - (n-1)
      {
        /* code */
       if( (matches[i] ^ matches[i+1]) == 0){
        res = "YES";
       }
      }
      cout<<res<<endl;
  }

}
