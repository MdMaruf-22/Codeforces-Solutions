#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
vector<pair<int,int>> tree[N];
vector<bool> vis(N);
vector<int> tme(N);

void dfs(int vertex,int time_tak){
    vis[vertex] = true;
    for(auto child:tree[vertex]){
        int vrte = child.first;
        int tim = child.second;
        if(vis[vrte]) continue;
        tme[vrte] = (tim<time_tak) + tme[vertex];
        dfs(vrte,tim);
    }
}
void reset(int n){
    for(int i=0;i<=n;i++){
        tree[i].clear();
        tme[i]=0;
        vis[i]=false;
    }
}
void solve()
{
    int n;
    cin>>n;
    reset(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back({v,i+1});
        tree[v].push_back({u,i+1});
    }
    tme[1] = 0;
    dfs(1,n);
    int mx = INT_MIN;
    for(int i=1;i<=n;i++) mx = max(mx,tme[i]);
    cout<<mx<<endl;
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
