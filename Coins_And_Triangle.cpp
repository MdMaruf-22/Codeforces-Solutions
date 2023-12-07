#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    int lo=1,hi=INT_MAX;
    int ans=0;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int val = (mid*(mid+1))/2;
        
        if(val<=n) {
            lo=mid+1;
            ans=mid;
        }
        else hi=mid;
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
