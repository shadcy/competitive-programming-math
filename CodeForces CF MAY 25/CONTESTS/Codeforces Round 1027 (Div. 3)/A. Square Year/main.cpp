#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int year = stoi(s);
        bool gotta = false;

        for (int a = 0; a <= 99; ++a) {
            for (int b = 0; b <= 99; ++b) {
                int sum = a + b;
                if (sum * sum == year) {
                    cout << a << " " << b << endl;
                    gotta = true;
                    goto done;
                }
            }
        }

        done:
        if (!gotta) cout << -1 << endl;
    }
    return 0;
}
