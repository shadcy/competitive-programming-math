#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string vec_1, vec_2, ans;

    cin >> vec_1 >> vec_2;

    int n = vec_1.size(); // now this will be correct

    for (int i = 0; i < n; i++) {
        ans.push_back(vec_1[i] == vec_2[i] ? '0' : '1');
    }

    cout << ans << '\n';
}
