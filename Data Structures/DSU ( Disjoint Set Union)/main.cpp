/*
 * Author: Shreyash (shadcy)
 * Created: 2025-08-06
 */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
Disjoint Set Union ( DSU )

   Features
   # Path Compression
   # Union by Rank ( to keep trees flat )
*/

class DSU
{
private:
    /* data */
    vector<int> parent, rank;

public:
    // Constructor

    DSU(int n)
    {
        // resize(n, x) changes the container size to n,
        // adding elements with value x if expanded, or
        // removing from the end if reduced.

        // but if use .resize(n) without explicitly mentioning the x
        // by default the value will be 0, if grows

        /*
        Parent[i] : tells who is the parent node of i

        rank[i] : helps optimize union operation ( used for balencing the tree )
        */
        parent.resize(n);
        rank.resize(n, 0);

        /*
        this is important in the start the rank list must be init to 0s
        and incresase the rank while proceeding
        */

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            // initally every node is parent of itself
        }
    }

    /*
    Now find(int x) will determine which set a particular element is in

    Finds the representative (root) of the set that x belongs to

    Path Compression : Flattens the structure by makling every node directly point to the root
    .This generally speeds up future find operations.
    */
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return; /* Already in the same set */

        /*
        In union by rank we generally attach the smaller tree under the larger tree
        and thats why keeping our tree balanced somehow;
        */

        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            /*Here we know that both are equals and there can be 2 cases
            * parent[rootX] = rootY

            * paremt[rootY] = rootX
            In this we took rootX as the bigger tree than Y
            you can also do anotehr way.
            */
            rank[rootX]++;
        }
    }
};

int main()
{
    DSU dsu(5); // 5 elements: 0 to 4

    dsu.unite(0, 2);
    /*
      After unite(0, 2):
      [0]------[2]
       |
     rank = 1
      parent[2] = 0
    */

    dsu.unite(4, 2);
    /*
      After unite(4, 2):
      [0]------[2]
       |
      [4]
       |
     parent[4] = 0
     parent[2] = 0
     rank of [0] = 1 (unchanged)
    */

    dsu.unite(3, 1);
    /*
      After unite(3, 1):
      [3]------[1]
       |
     rank of [3] = 1
     parent[1] = 3
    */

    cout << "Find(4): " << dsu.find(4) << endl;
    /*
      dsu.find(4) -> root is 0
      output: 0
    */

    cout << "Find(3): " << dsu.find(3) << endl;
    /*
      dsu.find(3) -> root is 3
      output: 3
    */

    if (dsu.find(0) == dsu.find(4))
        cout << "0 and 4 are in the same set\n";
    else
        cout << "0 and 4 are in different sets\n";
    /*
      0 and 4 are in same set (both have root 0)
      Output: 0 and 4 are in the same set
    */

    return 0;
}
