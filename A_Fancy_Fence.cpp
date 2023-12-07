#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a;
    cin >> a;
    if (360 % (180 - a) == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
