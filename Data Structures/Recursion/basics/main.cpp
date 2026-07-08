/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-05
 */

#include <iostream>
using namespace std;


int recursion(){
    recursion();
    return 55;
}
int main() {

    // infinite recursion
    cout<<recursion();


    //segmentation fault
    return 0;
}
