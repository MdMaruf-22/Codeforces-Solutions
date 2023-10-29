#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    int cnt2=0,cnt5=0;
    int rem = n;
    while(n>0 && n%5==0){
        n/=5;
        cnt5++;
    }
    while(n>0 && n%2==0){
        n/=2;
        cnt2++;
    }
    int val=1;
    int ext;
    while(cnt5<cnt2 && val*5<=k){
        cnt5++;
        val*=5;
    }
    while(cnt2<cnt5 && val*2<=k){
        cnt2++;
        val*=2;
    }
    while(val*10<=k) val*=10;
    int ans ;
    if(val==1) ans = rem*k;
    else{
        val = val* (k/val);
        ans = rem * val;
    }
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
