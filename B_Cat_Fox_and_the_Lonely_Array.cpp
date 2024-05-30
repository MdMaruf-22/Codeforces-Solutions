#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 1;
    for (int i = 0; i < 32; i++){
        int bit = 1 << i;
        int cnt = 0;
        int k = 0;
        for (int j = 0; j < a.size(); j++){
            if (!(a[j] & bit)){
                cnt++;
            }
            else{
                k = max(k, cnt);
                cnt = 0;
            }
        }
        k = max(k, cnt);
        if (cnt < a.size()){
            ans = max(ans, k + 1);
        }
    }

    cout << ans << endl;
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
