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
vi adj[N];
int n, m;

vi dis, low;

void solve()
{
    cin >> n >> m;
    dis.assign(n + 1, 0);
    low.assign(n + 1, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 1;
    cin >> t;
    while (t--)
    {
        // cout<<"Case "<<cs++<<": ";
        solve();
    }
    return 0;
}