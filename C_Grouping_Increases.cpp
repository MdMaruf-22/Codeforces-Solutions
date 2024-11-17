#include <bits/stdc++.h>
using namespace std;

#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    int ans = 0;
    int x = INT_MAX, y = INT_MAX;
    for (int i = 0; i < vc.size(); i++) {
        if(x>y) swap(x,y);
        if(vc[i]<=x) x=vc[i];
        else if(vc[i]<=y) y=vc[i];
        else {
            x=vc[i];
            ans++;
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
    while (t--) {
        solve();
    }
    return 0;
}
