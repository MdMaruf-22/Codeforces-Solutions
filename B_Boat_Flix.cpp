#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    double n,k;cin>>n>>k;
    double d,x,y;cin>>d>>x>>y;
    double ans;
    if(x>=y){
        ans = d/x;
    }
    else if(n<=k){
        ans = d/y;
    }
    else{
        int boat = k;
        double time = boat*(d/y);
        int rem = n-k;
        double rem_time = rem*d/x;
        ans = time+rem_time;
        ans /= n;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
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
