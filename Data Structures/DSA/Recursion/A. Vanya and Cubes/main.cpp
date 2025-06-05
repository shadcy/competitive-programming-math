#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int height = 0;
    int totalCubes = 0;
    int level = 1;

    while (true) {
        int cubesNeeded = level * (level + 1) / 2;
        if (totalCubes + cubesNeeded > n)
            break;
        totalCubes += cubesNeeded;
        height++;
        level++;
    }

    cout << height << endl;
    return 0;
}
