/*
 * Author: Shreyash (shadcy)
 * Created: 2025-08-03
 */

//  Implementation of brian's algorithm
/*
    Algorithm is used for finding the set bits in the binary seq
    a clever bit manipulation technique used to count the number of set bits (1s)
    in the binary representation of an integer.
    e.g. 
    Let’s imagine you're playing with LEGO blocks. Each block has little bumps on top. Think of each bump as a "1" and a flat spot as a "0".

    We want to count how many bumps (1s) are on a LEGO line (binary number). For example:

    13 = 1101 → bump, bump, flat, bump → 3 bumps
*/
#include <iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    
    /*

    n & (n - 1) must give bumps in n

    For Example: n = 13

    13 & 12 => 12 see we have 13 => 1101 and after n & (n - 1) this 
    will remove the last set bit 
    and we gonna have 1100 => 12 such that after again n & (n - 1) we'll have 
    1000 => 8 and so on 0

    */
    int count_bits=0;
    while(n > 0){
       n = n & (n-1);
       count_bits++;
    }
    cout<<count_bits;
    // cout<<(n & (n - 1))<<"\n";
    return 0;
}

/*
    * APPLICATIONS *

    1. Count the number of set bits in the number

    2. Check if the number is power of 2 or not 

    3. Find the hamming weight (Hamming weight is number of 1s in the binary form)

    4. Hamming Distance (Hamming Distance between two numbers = number of differing bits)

    int hammingDistance(int x, int y) {
    return countSetBits(x ^ y); // XOR and count 1s
    }


    e.t.c


*/