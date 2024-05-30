#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    a[0] = b[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    vector<int> ans(k + 1);
    ans[0] = 0;
    if (k == 1)
    {
        ans[1] = b[1]/a[1];
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            ans[i] = (a[i] - a[i - 1]) / (b[i] - b[i - 1]);
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (k == 1)
        {   
            cout << x << endl;
            continue;
        }
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        int cal = ans[pos - 1] * a[pos - 1];
        int fck = x - a[pos - 1];
        int div = fck / ans[pos];
        cout << cal + div << " ";

        // cout<<pos<<endl;
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
