#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Calculate minimum turns for Gellyfish to win
        // Option 1: Kill Flower's knight first, then attack Flower
        long long gellyfish_turns1 = d + b;
        // Option 2: Attack Flower directly
        long long gellyfish_turns2 = b;
        long long gellyfish_min_turns = min(gellyfish_turns1, gellyfish_turns2);
        
        // Calculate minimum turns for Flower to win
        // Option 1: Kill Gellyfish's knight first, then attack Gellyfish
        long long flower_turns1 = c + a;
        // Option 2: Attack Gellyfish directly
        long long flower_turns2 = a;
        long long flower_min_turns = min(flower_turns1, flower_turns2);
        
        // Since Gellyfish goes first (odd turns), Gellyfish wins if they can win
        // in the same number of turns or fewer than Flower
        // We need to account for the turn order:
        // Gellyfish moves on turns 1, 3, 5, ...
        // Flower moves on turns 2, 4, 6, ...
        
        // If both need n turns, Gellyfish wins because they go first
        // Gellyfish needs ceil(gellyfish_min_turns) actual game rounds
        // Flower needs ceil(flower_min_turns) actual game rounds
        // But Flower's first move is on turn 2, so if they need n moves,
        // they finish on turn 2n
        // Gellyfish finishes on turn 2n-1 if they need n moves
        
        long long gellyfish_finish_turn = 2 * gellyfish_min_turns - 1;
        long long flower_finish_turn = 2 * flower_min_turns;
        
        if (gellyfish_finish_turn <= flower_finish_turn) {
            cout << "Gellyfish\n";
        } else {
            cout << "Flower\n";
        }
    }
    
    return 0;
}