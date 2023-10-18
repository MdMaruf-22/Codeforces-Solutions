#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    // vector<int> a(n),b(n);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int, int>> vc(n);
    for (int i = 0; i < n; i++)
    {
        vc[i].first = a[i];
        vc[i].second = i;
    }
    sort(vc.begin(), vc.end());
    sort(b, b + n);
    vector<int> nw(n);
    for (int i = 0; i < n; i++)
    {
        nw[vc[i].second] = b[i];
    }
    for (auto x : nw)
        cout << x << " ";
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
