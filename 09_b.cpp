#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using oset = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n";
typedef long long ll;
typedef vector<int> vi;

const int N = 1e5 + 7;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    oset<pair<int, int>> s;
    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        s.insert({a[i], i});
        int temp = s.order_of_key({a[i], i});
        if (temp)
        {
            cnt += temp;
            for (int j = 0; j < temp; j++)
            {
                // cout << j << '.' << (*s.find_by_order(j)).first << endl;
                ans.push_back({i - 1, (*s.find_by_order(j)).second - 1});
            }
        }
    }
    cout << cnt << endl;
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x.first << ' ' << x.second << endl;
    }
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