#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x, y;
        cin >> x >> y;
        int two = (y + 1) / 2;
        int rem = (two * 15) - (y * 4);
        int remone = max(0LL, x - rem);
        int one = (remone + 14) / 15;
        int total_screens = two + one;
        cout << total_screens << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
