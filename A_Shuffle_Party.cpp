#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int num;
    cin >> num;
    int pw = 1 << (31 - __builtin_clz(num));
    cout<<pw<<endl;
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
