#include <bits/stdc++.h>
using namespace std;

int minOf(long long a, long long b){
  if(a > b) return b;
  else return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;
    cin >> t;
    
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        int odd = minOf(b, d), even = minOf(a, c);

        if(odd <= even){
            cout<<"Gellyfish"<<endl;
        }
        else{
            cout<<"Flower"<<endl;
        }
        

    }
    
    return 0;
}