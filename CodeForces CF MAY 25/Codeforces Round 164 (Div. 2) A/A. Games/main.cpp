#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int dist[t][2];  // dist[i][0] = home, dist[i][1] = guest

    for (int i = 0; i < t; i++) {
        cin >> dist[i][0] >> dist[i][1];
    }

    int res = 0;

    // Loop through each possible (host, guest) pair
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (i != j) {
                if (dist[i][0] == dist[j][1]) {
                    res++;
                }
            }
        }
    }

    cout << res;
    return 0;
}
