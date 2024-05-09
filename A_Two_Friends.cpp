#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n+1);
    int res=3;
    for(int i=1;i<=n;i++) cin>>vc[i];;
    for(int i=1;i<=n;i++){
        int cnt=3;
        if(i==vc[i]) cnt--;
        if(vc[i]==vc[vc[i]]) cnt--;
        if(i==vc[vc[i]]) cnt--;
        res = min(cnt,res);
    }
    cout<<res<<endl;
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
