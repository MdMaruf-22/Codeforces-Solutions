#include<bits/stdc++.h> 
using namespace std;
#define int long long 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++)
    {
        if (k == 0)
        {
            break;
        }
        if (i == n - 1)
        {
            break;
        }
        int diff = a[i] - a[i + 1];
        int r = min(diff, k);
        a[i + 1] += r;
        k -= r;
        i++;
    }
    int oddindexsum = 0;
    int evenindexsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evenindexsum += a[i];
        }
        else
        {
            oddindexsum += a[i];
        }
    }
    cout << abs(oddindexsum - evenindexsum) << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
