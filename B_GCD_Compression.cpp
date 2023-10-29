#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(2*n);
    vector<int> ev,od;
    for(int i=0;i<2*n;i++){
        cin>>vc[i];
    }
    
    for(int i=0;i<vc.size();i++){
        if(vc[i]%2) od.push_back(i+1);
        else ev.push_back(i+1);
    }
    vector<pair<int,int>> pr;
    for(int i=1;i<ev.size();i+=2) pr.push_back({ev[i-1],ev[i]});
    for(int i=1;i<od.size();i+=2) pr.push_back({od[i-1],od[i]});
    for(int i=0;i<n-1;i++) cout<<pr[i].first<<" "<<pr[i].second<<endl;
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
