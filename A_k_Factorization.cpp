#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    int cnt=n;
    vector<int> ans;
    for(int i=2;i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    if(k>ans.size()){
        cout<<-1<<endl;
        return;
    }
    int cal=1;
    for(int i=0;i<k-1;i++){
        cout<<ans[i]<<" ";
        cal*=ans[i];
    }
    cout<<cnt/cal<<endl;
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
