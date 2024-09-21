#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n,k;cin>>n>>k;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    for(int i=0;i<n;i+=k){
        for(int j=0;j<n;j+=k){
            cout<<grid[i][j];
        }
        cout<<endl;
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
