#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero(x) __builtin_ctz(x)
#define count_leading_zero(x) __builtin_clz(x)

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> vc(m+1);
    for(int i=0;i<=m;i++) cin>>vc[i];
    int fedor = vc[m];
    int ans = 0;
    for(int i=0;i<m;i++){
        int diff = fedor^vc[i];
        int one = give_number_of_one_in_binary(diff);
        if(one<=k) ans++;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
