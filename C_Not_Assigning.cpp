#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
vector<int> tree[N];
vector<bool> vis(N);
vector<int> indegree(N),edges,ans(N);

void dfs(int vertex){
    vis[vertex]=true;
    for(auto child:tree[vertex]){
        if(vis[child]) continue;
        edges.push_back(child);
        dfs(child);
    }
}


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        tree[i].clear();
        vis[i]=false;
        indegree[i]=0;
        ans[i]=0;
        edges.clear();
    }
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indegree[u]+=1;
        indegree[v]+=1;
    }
    int mx = *max_element(indegree.begin(),indegree.end());
    if(mx>2){
        cout<<-1<<endl;
        return;
    }
    int leaf=0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==1){
            leaf = i;
        }
    }
    dfs(leaf);
    int prime=2;
    for(auto x:edges){
        ans[x]=prime;
        prime = 5-prime;
    }
    for(int i=1;i<=n-1;i++) cout<<ans[i]<<" ";
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
