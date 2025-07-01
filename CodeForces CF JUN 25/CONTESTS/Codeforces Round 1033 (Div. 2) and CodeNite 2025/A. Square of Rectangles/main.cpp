#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> dim(6);
        for (int i = 0; i < 6; i++) {
            cin >> dim[i];
        }
        vector<pair<int, int>> rect;
        rect.push_back(make_pair(dim[0], dim[1]));
        rect.push_back(make_pair(dim[2], dim[3]));
        rect.push_back(make_pair(dim[4], dim[5]));

        int area = 0;
        for (int i = 0; i < 3; i++) {
            area += rect[i].first * rect[i].second;
        }

        int s = 1;
        while (s * s < area) {
            s++;
        }
        if (s * s != area) {
            cout << "NO\n";
            continue;
        }

        if (rect[0].second == s && rect[1].second == s && rect[2].second == s) {
            if (rect[0].first + rect[1].first + rect[2].first == s) {
                cout << "YES\n";
                continue;
            }
        }

        if (rect[0].first == s && rect[1].first == s && rect[2].first == s) {
            if (rect[0].second + rect[1].second + rect[2].second == s) {
                cout << "YES\n";
                continue;
            }
        }

        bool found = false;

        for (int i = 0; i < 3 && !found; i++) {
            vector<pair<int, int>> others;
            for (int j = 0; j < 3; j++) {
                if (j != i) {
                    others.push_back(rect[j]);
                }
            }
            if (rect[i].first != s) continue;
            if (others[0].second != others[1].second) continue;
            if (others[0].first + others[1].first != s) continue;
            if (others[0].second + rect[i].second != s) continue;
            found = true;
        }

        if (found) {
            cout << "YES\n";
            continue;
        }

        found = false;
        for (int i = 0; i < 3 && !found; i++) {
            vector<pair<int, int>> others;
            for (int j = 0; j < 3; j++) {
                if (j != i) {
                    others.push_back(rect[j]);
                }
            }
            if (rect[i].first != s) continue;
            if (others[0].second != others[1].second) continue;
            if (others[0].first + others[1].first != s) continue;
            if (rect[i].second + others[0].second != s) continue;
            found = true;
        }

        if (found) {
            cout << "YES\n";
            continue;
        }

        found = false;
        for (int i = 0; i < 3 && !found; i++) {
            vector<pair<int, int>> others;
            for (int j = 0; j < 3; j++) {
                if (j != i) {
                    others.push_back(rect[j]);
                }
            }
            if (rect[i].second != s) continue;
            if (others[0].first != others[1].first) continue;
            if (others[0].second + others[1].second != s) continue;
            if (others[0].first + rect[i].first != s) continue;
            found = true;
        }

        if (found) {
            cout << "YES\n";
            continue;
        }

        found = false;
        for (int i = 0; i < 3 && !found; i++) {
            vector<pair<int, int>> others;
            for (int j = 0; j < 3; j++) {
                if (j != i) {
                    others.push_back(rect[j]);
                }
            }
            if (rect[i].second != s) continue;
            if (others[0].first != others[1].first) continue;
            if (others[0].second + others[1].second != s) continue;
            if (rect[i].first + others[0].first != s) continue;
            found = true;
        }

        if (found) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}