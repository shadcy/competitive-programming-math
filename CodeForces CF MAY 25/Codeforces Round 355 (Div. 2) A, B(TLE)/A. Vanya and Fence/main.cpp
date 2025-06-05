#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int num, height;
  cin>>num>>height;

  int heightArray[num];
  int counter = 0;

  for (int i = 0; i < num; i++)
  {
    /* code */
    cin>>heightArray[i];
  }

  for (int i = 0; i < num; i++)
  {
    if (heightArray[i] > height)
    {
        /* code */
        counter+=2;
    }
    else{
        counter+=1;
    }
  }

  cout<<counter;
}

