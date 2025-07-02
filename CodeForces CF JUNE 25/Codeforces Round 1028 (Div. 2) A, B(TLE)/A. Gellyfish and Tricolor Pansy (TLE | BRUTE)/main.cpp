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
        bool end = 1;
        bool winner = 1; // flower wins
        int k=1, odd = minOf(b, d), even = minOf(a, c);
        while (end)
        {
            /* code */
            if(k%2 <= 0){
             even -= 1;
             if(even == 0){
                //flower wins
                end = 0;
             }
            }
            else{
                odd -= 1;
                if(odd <= 0){
                   //gelly wins
                   winner = 0;
                   end = 0;
                }
            }
            k++;
        }

        if(winner){
            cout<<"Flower"<<endl;
        }
        else{
            cout<<"Gellyfish"<<endl;
        }
        

    }
    
    return 0;
}