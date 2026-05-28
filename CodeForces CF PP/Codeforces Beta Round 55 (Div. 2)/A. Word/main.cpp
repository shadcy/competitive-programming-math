#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int lower_count = 0, upper_count = 0;

    // Count lowercase and uppercase letters
    for (char c : s) {
        if (islower(c))
            lower_count++;
        else
            upper_count++;
    }

    // Convert the string based on the count
    if (upper_count > lower_count) {
        for (char &c : s) c = toupper(c);
    } else {
        for (char &c : s) c = tolower(c);
    }

    cout << s << endl;
    return 0;
}
