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

const int N = 1e5 + 10;
int n, m;

vector<pair<int, int>> adj[N];

// DSU
vi par(N, -1), size(N, 0);
void make(int idx)
{
    par[idx] = idx;
    size[idx] = 1;
}

int find(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = find(par[node]);
}

int Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        if (size[u] < size[v])
            swap(u, v);
        par[v] = u;
        size[u] += size[v];
    }
}
// dsu ends;

vector<pair<int, pair<int, int>>> edges;
void krushkal()
{
    int total_weight = 0;
    for (auto &e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        cout << u << ' ' << v << endl;
        total_weight += w;
    }
    cout << total_weight << endl;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        make(i);
    krushkal();
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