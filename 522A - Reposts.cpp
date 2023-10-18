#include<bits/stdc++.h>
using namespace std;
#define int long long

map<string,vector<string>> tree;
map<string,bool> vis;
map<string,int> dist;
void dfs(string vertex){
    vis[vertex] = true;
    for(string child:tree[vertex]){
        if(vis[child]) continue;
        dfs(child);
        dist[vertex] =max(dist[vertex],dist[child]+1);
    }
}

void solve()
{
    int n;cin>>n;
    string dm;
    getline(cin,dm);
    for(int i=0;i<n;i++){
        string x;
        getline(cin,x);
        size_t ind = x.find(" reposted ");
        string a = x.substr(0,ind);
        string b =x.substr(ind+10);
        transform(a.begin(),a.end(),a.begin(),::tolower);
        transform(b.begin(),b.end(),b.begin(),::tolower);
        tree[b].push_back(a);
        tree[a].push_back(b);
    }
    dfs("polycarp");
    int mx = INT_MIN;
    for(auto x:dist) mx = max(mx,x.second);
    cout<<mx+1<<endl;
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
