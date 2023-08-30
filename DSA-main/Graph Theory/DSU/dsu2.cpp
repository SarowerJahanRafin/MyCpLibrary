// implementation of dsu using linked list and union by rank

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *parent;
    int rank;

    Node()
    {
        value = INT_MIN;
        parent = NULL;
        rank = 0;
    }

    Node(int value)
    {
        this->value = value;
        parent = this;
        rank = 0;
    }
};

class DSU
{
private:
    int n;

public:
    Node *nodes;

    DSU(int n)
    {
        this->n = n;
        nodes = new Node[n + 1];

        for (int i = 1; i <= n; i++)
        {
            makeset(i);
        }
    }

    void makeset(int value)
    {
        Node *node = new Node(value);
        nodes[value] = *node;
    }

    Node *find(Node *x)
    {
        if (x->parent != x)
        {
            x->parent = find(x->parent);
        }

        return x->parent;
    }

    void _union(Node *x, Node *y)
    {
        Node *rootX = find(x);
        Node *rootY = find(y);

        if (rootX != rootY)
        {
            if (rootX->rank < rootY->rank)
            {
                swap(rootX, rootY);
            }

            rootY->parent = rootX;

            if (rootX->rank == rootY->rank)
            {
                rootX->rank++;
            }
        }
    }
};