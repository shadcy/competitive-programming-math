#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        
        // optimal approach
        // ll squares = sqrt(n);
        // ll cubes = cbrt(n);
        // ll sixth = pow(n, 1.0 / 6.0);
        
        // cout << (squares + cubes - sixth) << '\n';
    
        //naive approach
        ll ans =0, both = 0;
        for (ll i = 1; i*i <= n; i++)
        {
            ans++;
        }
        for (ll i = 1; i*i*i <= n; i++)
        {
            ans++;
        }

        for (ll i = 1; i*i*i*i*i*i <= n ; i++)
        {
            both++;
        }

        cout<<ans-both<<endl;

        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
