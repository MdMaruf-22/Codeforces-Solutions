#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((c > a && c < b && (d < a || d > b)) || (c > b && c < a && (d < b || d > a)))
        cout << "YES\n";
    else if ((d > a && d < b && (c < a || c > b)) || (d > b && d < a && (c < b || c > a)))
        cout << "YES\n";
    else
        cout << "NO\n";
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
