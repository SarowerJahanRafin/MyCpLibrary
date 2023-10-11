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

const int N = 1e3 + 7;
int a[N], cnt[N][N], path[N][N];
int n;

void matrixChainOrder()
{
    memset(cnt, 0, sizeof cnt);
    memset(path, -1, sizeof path);
    for (int d = 2; d < n; d++)
    {
        for (int i = 1; i < n - d + 1; i++)
        {
            int col = i + d - 1;
            cnt[i][col] = INT_MAX;
            for (int k = i; k <= col - 1; k++)
            {
                int temp = cnt[i][k] + cnt[k + 1][col] + (a[i] * a[k + 1] * a[col + 1]);
                if (temp < cnt[i][col])
                {
                    cnt[i][col] = temp;
                    path[i][col] = k;
                }
            }
        }
    }
}
string finalAns = "";

void printPath(int st, int en)
{
    // if (st > en)
    //     return;
    if (st == en)
    {
        // cout << 'A';
        finalAns.push_back('A');
    }
    else
    {
        // cout << '(';
        finalAns.push_back('(');
        if (path[st][en] != -1)
        {
            printPath(st, path[st][en]);
            printPath(path[st][en] + 1, en);
        }
        finalAns.push_back(')');
        // cout << ')';
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    matrixChainOrder();

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << cnt[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    printPath(1, n - 1);

    int charCount = 0;
    for (int i = 0; i < finalAns.size(); i++)
    {
        if (finalAns[i] >= 'A' and finalAns[i] <= 'Z')
        {
            finalAns[i] = 'A' + charCount;
            charCount++;
        }
    }
    cout << finalAns << endl;
    cout << "Optimal Cost is : ";
    cout << cnt[1][n - 1] << endl;
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