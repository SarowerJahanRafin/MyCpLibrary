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
int n;
struct point
{
    int x, y;
    // point(int xx, int yy)
    // {
    //     x = xx;
    //     y = yy;
    // }
};

bool compareY(point p, point q)
{
    return p.y < q.y;
}

ll distance(point c, point d)
{
    ll temp = (c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y);
    return temp;
}
const int N = 1e5 + 5;
point a[N];
bool compareX(point p, point q)
{
    return p.x < q.x;
}

pair<point, point> bruteforces(point u, point v, point w)
{
    ll d_uv = distance(u, v);
    ll d_vw = distance(v, w);
    ll d_uw = distance(u, w);

    ll mini = min(d_uv, d_uw);
    mini = min(mini, d_vw);
    if (mini == d_uv)
        return {u, v};
    else if (mini == d_uw)
        return {u, w};
    else
        return {v, w};
}

pair<point, point> findTwoClosestPoint(int st, int en)
{

    int len = en - st + 1;
    if (len == 3)
    {
        return bruteforces(a[st], a[st + 1], a[st + 2]);
    }
    if (len == 2)
    {
        return {a[st], a[en]};
    }
    pair<point, point> ans;

    int mid = st + (en - st) >> 1;
    auto left = findTwoClosestPoint(st, mid);
    auto right = findTwoClosestPoint(mid + 1, en);
    int tempDistance = min(distance(left.first, left.second), distance(right.first, right.second));

    vector<point> s;
    for (int i = st; i <= en; i++)
    {
        if (abs(a[i].x - a[mid].x) < tempDistance)
            s.push_back(a[i]);
    }

    sort(s.begin(), s.end(), compareY);
    if (tempDistance == distance(left.first, left.second))
        ans = left;
    else
        ans = right;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size() && j <= i + 7; j++)
        {
            ll temp = distance(a[i], a[j]);
            if (temp < tempDistance)
            {
                tempDistance = temp;
                ans = {a[i], a[j]};
            }
        }
    }
    return ans;
}

void printThePoint(pair<point, point> p)
{
    cout << p.first.x << ' ' << p.first.y << endl;
    cout << p.second.x << " " << p.second.y << endl;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, compareX);

    auto theClosestPoint = findTwoClosestPoint(0, n - 1);
    double finalDistance = sqrt(1.00 * distance(theClosestPoint.first, theClosestPoint.second));
    cout << setprecision(15) << finalDistance << endl;

    printThePoint(theClosestPoint);
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