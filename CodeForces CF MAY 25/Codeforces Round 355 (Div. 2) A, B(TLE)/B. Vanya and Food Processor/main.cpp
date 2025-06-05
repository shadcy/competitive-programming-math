#include <iostream>
using namespace std;

int main() {
  int num, height, k;
  cin>> num >> height >> k;

  int temp_sum = 0;

  int heightArray[num];
  int counter = 0;
  int time = 0;

  for (int i = 0; i < num; i++)
  {
    /* code */
    cin>>heightArray[i];
  }

  for (int i = 0; i < num; ) { // <== Note: no i++ here!
    if (temp_sum + heightArray[i] <= height) {
        temp_sum += heightArray[i];
        i++; // move to next piece only if current one fits
    } else {
        // smash one second
        time++;
        temp_sum = max(0, temp_sum - k); // process current load
    }
}

// Smash remaining potato
while (temp_sum > 0) {
    time++;
    temp_sum -= k;
}


  cout<<time;
}

