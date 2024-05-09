#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x; cin >> x;
    int mx = INT_MIN;
    int y = 1;
    for(int i = 2; i < x; i++) {
        int val = __gcd(x, i) + i;
        if(val > mx) {
            mx = val;
            y = i;
        }
    }
    cout << y << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
