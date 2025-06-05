#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define endl '\n'
#define pb push_back

// Main Function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n /= 2;
		if (n & 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++i) {
			cout << i * 2 << " ";
		}
		for (int i = 1; i < n; ++i) {
			cout << i * 2 - 1 << " ";
		}
		cout << 3 * n - 1 << endl;
	}
	
	return 0;
}
