#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--)
  {
   int a, b, c;
   cin>>a>>b>>c;
   int totalSum = a+b+c;
   //process the data yipee

   if(totalSum % 3 == 0) {
    int avgSum = totalSum/3;
    int left = max(avgSum, a) - min(avgSum, a) + max(avgSum, b) - min(avgSum, b);
    int right = c- avgSum;
    if(left == right) {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
   }
   else {
    cout<<"NO"<<endl;
   }

  }
  

}
