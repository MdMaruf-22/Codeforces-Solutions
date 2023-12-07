#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc;
    for(int i=1;i<=2*n;i++){
        int x;cin>>x;
        vc.push_back(x);
    }
    sort(vc.begin(),vc.end());
    int cst=0;
    set<pair<int,int>> p;
    for(int i=0;i<n-1;i++){
        cst+=(vc[i+1]-vc[i])+(vc[n+i+1]-vc[n+i]);
        p.insert({vc[n+i+1],vc[i+1]});
        p.insert({vc[n+i],vc[i]});
    }
    cout<<cst<<endl;
    for(auto x:p) cout<<x.first<<" "<<x.second<<endl;
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
