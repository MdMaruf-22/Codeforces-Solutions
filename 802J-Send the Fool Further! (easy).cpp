#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<pair<int,int>> tree[N];
vector<bool> vis(N);
vector<int> dis(N);
void dfs(int vertex){
    vis[vertex] = true;
    for(auto child:tree[vertex]){
        int val = child.first;
        int wt = child.second;
        if(vis[val]) continue;
        dis[val] = dis[vertex]+wt;
        dfs(val);
    }
}
void bfs(int vertex){
    queue<pair<int,int>> q;
    q.push({vertex,0});
    vis[vertex]=true;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(auto child:tree[p.first]){
            int ch = child.first;
            int wt = child.second;
            if(vis[ch]) continue;
            q.push({ch,wt});
            vis[ch] = true;
            dis[ch] = dis[p.first]+wt;
        }
    }
}

void solve()
{
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,c;
        cin>>u>>v>>c;
        tree[u].push_back({v,c});
        tree[v].push_back({u,c});
    }
    dfs(0);
    cout<<*max_element(dis.begin(),dis.end())<<endl;
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
