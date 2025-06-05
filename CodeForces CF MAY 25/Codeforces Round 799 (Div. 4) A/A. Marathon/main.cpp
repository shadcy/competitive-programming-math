#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--)
  {
    /* code */
   int ans = 0;
   int dist[4];
   for (int i = 0; i < 4; i++)
   {
    /* code */
    cin>>dist[i];
   }
   // Taking input is done here 
   // Now process the data
 for (int i = 1; i < 4; i++)
 {
    /* code */
    if(dist[i] > dist[0]) {
        ans++;
    }
 }
 
cout<<ans<<endl;
   

  }
  

}
