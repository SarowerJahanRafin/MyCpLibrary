// implementation of dsu using array and union by rank

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int n;       // total node number
    int *parent; // for storing root
    int *rank;   // for storing height

public:
    DSU(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        makeset();
    }

    void makeset()
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) // find function with path compression
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void _union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }

};

int main()
{
    int n = 6;
    DSU dsu(n);

    dsu._union(1, 2);
    dsu._union(2, 3);
    dsu._union(4, 5);
    dsu._union(1, 5);

    cout << "Parent array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    return 0;
}