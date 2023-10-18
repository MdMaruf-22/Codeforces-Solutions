#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
vector<int> tree[N];
vector<bool> vis(N);
vector<int> level(N);
vector<pair<int,int>> vc;
void bfs(int vertex){
    queue<int> q;
    q.push(vertex);
    level[vertex] = 1;
    while(!q.empty()){
        vertex = q.front();
        q.pop();
        vis[vertex] = true;
        vc.push_back({vertex,level[vertex]});
        for(auto child:tree[vertex]){
            if(vis[child]) continue;
            level[child] = level[vertex]+1;

            q.push(child);
            vis[child]=true;
        }
    }
}
void bfs2(int vertex){
    queue<int> q;
    q.push(vertex);
    level[vertex] = 1;
    while(!q.empty()){
        vertex = q.front();
        q.pop();
        vis[vertex] = true;
        for(auto child:tree[vertex]){
            if(vis[child]) continue;
            level[child] = level[vertex]+1;
            q.push(child);
            vis[child]=true;
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    bfs(1);
    int mx = *max_element(level.begin(),level.end());
    if(mx==3) mx=1;
    else if(mx%2) mx = mx/2+1;
    else mx = mx/2;
    
    vector<int> nw ;
    for(int i=1;i<=n;i++){
        if(level[i]==mx) nw.push_back(i);
    }
    int root;
    if(nw.size()==1) root = nw[0];
    else{
        for(auto x:nw){
        if(tree[x].size()>1){
            root = x;
            break;
            }
        }
    }
    //cout<<root<<endl;
    for(int i=1;i<=n;i++){
        level[i] = 0;
        vis[i]=false;
    }
    bfs2(root);
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[level[i]]++;
    // for(auto x:mp) cout<<x.first<<" "<<x.second<<endl;
    map<int, int>::iterator it = mp.begin();
    ++it;
    int a = it->second;
    ++it;
    int b = it->second;
    cout<<a<<" "<<b/a<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<N;i++){
            tree[i].clear();
            level[i] = 0;
            vis[i]=false;
        }
        solve();
    }
    return 0;
}
