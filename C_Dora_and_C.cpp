#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
void solve()
{
    int n,a,b;cin>>n>>a>>b;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int gcd = __gcd(a,b);
    for(int i=0;i<n;i++) vc[i]%=gcd;
    sort(vc.begin(),vc.end());
    int ran = vc[n-1] - vc[0];
    for(int i=1;i<n;i++){
        int curr = gcd-(vc[i]-vc[i-1]);
        ran = min(ran,curr);
    }
    cout<<ran<<endl;
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
