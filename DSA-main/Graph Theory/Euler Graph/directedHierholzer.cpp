#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n";
typedef long long ll;
typedef vector<int> vi;

const int N = 1e5 + 2;
vi adj[N];

class DirectedHierholzer
{
private:
    vi inDegree, outDegree;
    int nodes, edges, startNode = -1, endNode = -1;
    deque<int> ansPath;
    void countingDegrees()
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (auto v : adj[i])
            {
                outDegree[i]++, inDegree[v]++;
            }
        }
    }

    bool EulerianExists()
    {
        for (int i = 1; i <= nodes; i++)
        {
            if (abs(inDegree[i] - outDegree[i]) > 1)
                return false;
            if (outDegree[i] - inDegree[i] == 1)
            {
                if (startNode == -1)
                    startNode = i;
                else
                    return false;
            }
            else if (inDegree[i] - outDegree[i] == 1)
            {
                if (endNode == -1)
                    endNode = i;

                else
                    return false;
            }
        }
        if ((startNode == -1 and endNode == -1) or (startNode != -1 and endNode != -1))
            return 1;
        return false;
    }

    void dfs(int nodeat)
    {
        while (outDegree[nodeat] != 0)
        {
            auto to = adj[nodeat][outDegree[nodeat]];
            outDegree[nodeat]--;
            dfs(to);
        }
        ansPath.emplace_front(nodeat);
    }

public:
    void build(int n, int m)
    {
        nodes = n;
        edges = m;
        outDegree.assign(nodes + 2, 0);
        inDegree.assign(nodes + 2, 0);
    }

    void EulerPath()
    {
        countingDegrees();
        bool possible = EulerianExists();
        if (!possible)
        {
            cout << "Nothing \n";
            return;
        }
        if (startNode != -1)
        {
            dfs(startNode);
        } // you can do it by anynode i believe;
        else
        {
            for (int i = 1; i <= nodes; i++)
                if (outDegree[i] > 0)
                {
                    dfs(i);
                    break;
                }
        }

        if (ansPath.size() == edges + 1)
        {
            while (ansPath.size() != 1)
            {
                cout << ansPath.front() << " ";
                ansPath.pop_front();
            }
            cout << ansPath.front() << endl;
        }
        else
        {
            cout << "sorry vai, path pai nai kno\n";
        }
    }
};

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 1;
    // cin >> t;
    while (t--)
    {
        // cout<<"Case "<<cs++<<": ";
        solve();
    }
    return 0;
}