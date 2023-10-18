#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
vector<int> tree[N];
vector<bool> vis(N);
vector<int> cost(N);
int mn = INT_MAX;
void dfs(int vertex){
    vis[vertex] = true;
    mn = min(mn,cost[vertex]);
    for(auto child:tree[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int cst;cin>>cst;
        cost[i] = cst;
    }
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int ans =0 ;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        mn = INT_MAX;
        dfs(i);
        ans+=mn;
    }
    cout<<ans<<endl;
    
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
