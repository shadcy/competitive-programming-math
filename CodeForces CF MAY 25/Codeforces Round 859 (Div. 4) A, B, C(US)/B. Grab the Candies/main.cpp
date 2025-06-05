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
   int arr[n];
   
   int even = 0; // Mihai takes it
   int odd = 0; // Bianca takes it

   for (int i = 0; i < n; i++)
   {
    cin>>arr[i];
   }

   for (int i = 0; i < n; i++)
   {
    if(arr[i] % 2 == 0){
      even+= arr[i];
    }
    else{
      odd+= arr[i];
    }
   }

   if(even > odd){
    cout<<"YES"<<endl;
   }
   else{
    cout<<"NO"<<endl;
   }
  }
  

}
