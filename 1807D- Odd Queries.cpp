#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,q;cin>>n>>q;
    vector<int> arr(n),preSum(n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        preSum[i+1]=preSum[i]+arr[i];
    }
    while(q--){
        int l,r,k;cin>>l>>r>>k;
        int newSum=preSum[n]-(preSum[r]-preSum[l-1])+(r-l+1)*k;
        if(newSum%2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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
