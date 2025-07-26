#include <bits/stdc++.h>
using namespace std;
#define int long long
int find_mex(const vector<int> &vc1)
{
    vector<bool> mx(4, false);
    for (int val : vc1)
    {
        if (val >= 0 && val < 4)
        {
            mx[val] = true;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (!mx[i])
        {
            return i;
        }
    }
    return 0;
}

void calc(vector<int> &vc, int n, int x, int y, int ind)
{
    if (ind == x)
        return;
    int left = vc[(ind - 1 + n) % n];
    int right = vc[(ind + 1) % n];
    if (ind == y) vc[ind] = find_mex({left, right, vc[x]});
    else vc[ind] = find_mex({left, right});
    calc(vc, n, x, y, (ind + 1) % n);
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<int> vc(n, -1);
    vc[x] = 0;
    vc[y] = 1;
    calc(vc, n, x, y, (x + 1) % n);
    for (int i = 0; i < n; i++)
    {
        cout << vc[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
