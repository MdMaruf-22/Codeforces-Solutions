#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
vector<pair<int,int>> tree[N];
vector<int> st_time(N),index(N);
void dfs(int vertex){
    for(auto child:tree[vertex]){
        if(st_time[child.first]==0){
            if(child.second>index[vertex]){
                st_time[child.first] = st_time[vertex];
                index[child.first] = child.second;
            }
            else{
                st_time[child.first] = st_time[vertex] + 1;
                index[child.first] = child.second;
            }
            dfs(child.first);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            tree[i].clear();
            st_time[i]=0;
            index[i]=0;
        }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back({v,i});
        tree[v].push_back({u,i});
    }
    st_time[1]=1;
    dfs(1);
    int mx=0;
    for(int i=1;i<=n;i++){
        mx = max(mx,st_time[i]);
    }
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
