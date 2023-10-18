#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc,permu;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vc.push_back(x);
        permu.push_back(i+1);
    }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n-1;i++){
        if(permu[i]==vc[i]) swap(permu[i],permu[i+1]);
    }
    if(vc[n-1]==permu[n-1]) swap(permu[n-1],permu[n-2]);
    for(auto x:permu) cout<<x<<" ";
    cout<<endl;
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
