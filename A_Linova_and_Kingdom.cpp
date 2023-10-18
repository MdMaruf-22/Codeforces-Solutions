#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
vector<int> tree[N];
vector<bool> vis(N);
vector<int> depth(N),cal(N),nw;

void dfs(int vertex){
    vis[vertex]=true;
    cal[vertex]=1;
    for(auto child:tree[vertex]){
        if(vis[child]) continue;
        depth[child] = depth[vertex]+1;
        dfs(child);
        cal[vertex] += cal[child];
    }
    nw.push_back(cal[vertex]-depth[vertex]-1);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    int cnt=0;
    k = n-k;
    sort(nw.rbegin(),nw.rend());
    for(int i=0;i<k;i++){
        cnt+= nw[i];
    }
    cout<<cnt<<endl;
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
