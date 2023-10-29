#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,c;cin>>n>>c;
    vector<int> vc(n+1);
    for(int i=1;i<=n;i++) cin>>vc[i];
    vector<int> preSum(n+1,0);
    for(int i=1;i<=n;i++){
        preSum[i]=preSum[i-1]+vc[i];
    }
    int index = 1;
    for(int i=2;i<=n;i++){
        if(preSum[index]+vc[i]>=i*c) index = i;
    }
    if(index==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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
