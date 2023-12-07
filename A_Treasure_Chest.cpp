#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (x >= y){
        cout << x << endl;
        return;
    }
    if (y - x <= k)
    {
        cout << y << endl;
        return;
    }

    cout << (2 * y - (x + k)) << endl;
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
