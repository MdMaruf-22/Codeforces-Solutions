#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    int mcnugget = 5*3-5-3;
    int ans=0;
    //Used chicken mcnugget theorem :)
    if(n>mcnugget){
        ans=0;
    }
    else if(n==1 || n==4 || n==7) ans=1;
    else if(n==2) ans=2;
    cout<<ans<<endl;
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
