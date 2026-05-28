#include <iostream>
#include <set>
using namespace std;

// Function to check if a year has all unique digits
bool hasDistinctDigits(int year) {
    string str = to_string(year);
    set<char> digits(str.begin(), str.end());
    return digits.size() == str.size(); // If size matches, all digits are unique
}


// we just need to check if the +1 to the year has distinct year or not 

//ye as simple as that
int main() {
    int y;
    cin >> y;

    while (true) {
        y++; // Check the next year
        if (hasDistinctDigits(y)) {
            cout << y << endl;
            break;
        }
    }
    
    return 0;
}
