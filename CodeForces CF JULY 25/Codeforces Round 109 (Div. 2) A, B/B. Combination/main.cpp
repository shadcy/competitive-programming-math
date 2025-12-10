#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    //this is fuckign cool and better to use pair instead of ass peron taking vectors for both

    // to show youself as a moron to cf usrers who stack your solutions
    //ahhhhh,  these ass holes and mother duxks 
    vector<pair<int, int>> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second; // ai, bi
    }
    
    // Separate cards into two categories
    vector<pair<int, int>> positive; // bi >= 1
    vector<int> zero_b; // bi == 0
    
    for (int i = 0; i < n; i++) {
        if (cards[i].second > 0) {
            positive.push_back(cards[i]);
        } else {
            zero_b.push_back(cards[i].first);
        }
    }
    
    // Sort positive cards by ai in descending order (greedy)
    sort(positive.begin(), positive.end(), greater<pair<int, int>>());
    
    // Sort zero_b cards by ai in descending order
    sort(zero_b.begin(), zero_b.end(), greater<int>());
    
    long long total_points = 0;
    int plays_available = 1; // Start with 1 play
    
    // Play all positive cards first
    for (auto card : positive) {
        if (plays_available > 0) {
            total_points += card.first;
            plays_available--; // Use one play
            plays_available += card.second; // Gain bi plays
        }
    }
    
    // Play as many zero_b cards as we can
    for (int i = 0; i < zero_b.size() && plays_available > 0; i++) {
        total_points += zero_b[i];
        plays_available--;
    }
    
    cout << total_points << endl;
    
    return 0;
}