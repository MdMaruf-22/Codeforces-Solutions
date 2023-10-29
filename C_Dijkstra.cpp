#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
const int INF = 1e9;
vector<pair<int,int>> graph[N];
vector<bool> vis(N);
vector<int> dist(N,INF);
vector<int> parent(N,-1);

void dijkastra(){
    set<pair<int,int>> s;
    s.insert({0,1});
    dist[1]=0;
    while(s.size()>0){
        auto node = *s.begin();
        int vertex = node.second;
        int wt = node.first;
        s.erase(s.begin());
        if(vis[vertex]) continue;
        vis[vertex]=true;
        for(auto child:graph[vertex]){
            int child_vertex = child.first;
            int child_wt = child.second;
            if(dist[child_vertex]==INF){
                dist[child_vertex] = dist[vertex]+child_wt;
                parent[child_vertex] = vertex;
                s.insert({dist[child_vertex],child_vertex});
            }
            else{
                if(dist[vertex]+child_wt<dist[child_vertex]){
                    s.erase({dist[child_vertex],child_vertex});
                    dist[child_vertex] = dist[vertex]+child_wt;
                    parent[child_vertex] = vertex;
                    s.insert({dist[child_vertex],child_vertex});
                }
            }
        }

    }
}
void solve()
{
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    dijkastra();
    if(dist[n]==INF) cout<<-1<<endl;
    else{
        vector<int> path;
        int vertex = n;
        while(vertex!=-1){
            path.push_back(vertex);
            vertex = parent[vertex];
        }
        //path.push_back(1);
        reverse(path.begin(),path.end());
        for(auto x:path) cout<<x<<" ";
        cout<<endl;
    }
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
