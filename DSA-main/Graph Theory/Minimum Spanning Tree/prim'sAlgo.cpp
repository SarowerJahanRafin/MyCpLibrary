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

const int N = 1e5 + 3;
int n, m;
vector<pair<int, int>> adj[N];

void prim()
{
    // first of all, take any node as a source node;
    int src = 1;
    set<pair<int, pair<int, int>>> st; // weigth,u,v;
    st.insert({0, {1, 1}});

    vector<bool> vis(n + 1, 0);
    int total_weight = 0;

    // you can run this loops for n times also ,if the set is empty before n times. so no spanning tree exists;
    while (!st.empty())
    {

        int u = (*st.begin()).second.first;
        int v = (*st.begin()).second.second;
        int w = (*st.begin()).first;

        st.erase(st.begin());
        if (vis[u] and vis[v])
            continue;
        vis[u] = vis[v] = 1;
        total_weight += w;
        cout << v << ' ';
        for (auto ed : adj[v])
        {
            int to = ed.first;
            int w = ed.second;
            if (to != u)
            {
                st.insert({w, {v, to}});
            }
        }
    }
    cout << endl;
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
        adj[v].push_back({u, w}); // for undirected graph;
    }
    prim();
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