/*
 * Author: Shreyash (shadcy)
 * Created: 2025-10-28
 * Template: Competitive Programming
 */

    // Your solution here
    //given we have a gcd (number, x) = 1 then that number, x must be co-prime
    
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Check if any element is 1
        bool hasOne = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                hasOne = true;
                break;
            }
        }
        
        if (hasOne) {
            cout << 2 << "\n";
            continue;
        }
        
        // Find GCD of all elements
        long long g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(g, a[i]);
        }
        
        // Find smallest prime not dividing g
        long long answer = -1;
        
        // Check x = 2
        if (g % 2 != 0) {
            answer = 2;
        } else {
            // Check odd numbers starting from 3
            for (long long x = 3; x <= 1000000; x += 2) {
                if (isPrime(x) && g % x != 0) {
                    answer = x;
                    break;
                }
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}

