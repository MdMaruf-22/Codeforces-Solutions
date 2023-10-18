#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
bool vis[N][N];

bool cmp(pair<int,int>& p1 , pair<int,int>& p2){
    if(p1.first == p2.first) return p1.second>p2.second;
    return p1.first<p2.first;
}

void solve()
{
    int n;cin>>n;
    vector<pair<int,int>> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i].first>>vc[i].second;
    sort(vc.begin(),vc.end(),cmp);
    for(int i=0;i<n-1;i++){
        if(vc[i].first!=vc[i+1].first) cout<<vc[i].first<<" "<<vc[i].second<<" "<<vc[i].first<<endl;
        else cout<<vc[i].first<<" "<<vc[i].second<<" "<<vc[i+1].second+1<<endl;
    }
    cout<<vc[n-1].first<<" "<<vc[n-1].second<<" "<<vc[n-1].first<<endl;
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
