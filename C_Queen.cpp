#include<bits/stdc++.h>
using namespace std;

#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
vector<vector<int>> tree;
vector<int> val; 
vector<int> vis;
vector<int> ans;

void dfs(int vertex,int parent){
    bool flag = val[vertex]==1?true:false;
    vis[vertex]=1;
    for(auto child:tree[vertex]){
        if(vis[child]) continue;
        dfs(child,vertex);
        if(val[child]==0) flag=false;
    }
    if(flag) ans.push_back(vertex);
}


void solve()
{
    int n;cin>>n;
    val.resize(n+1);
    tree.resize(n + 1);
    val.resize(n + 1);
    vis.resize(n + 1, false);
    int root = -1;
    for(int i = 1;i <= n;i++){
        int x;cin>>x;
        int y;cin>>y;
        val[i] = y;
        if(x==-1){
            root = i;
        }
        else{
            tree[i].push_back(x);
            tree[x].push_back(i);
        }
    }
    dfs(root,-1);
    if(ans.empty()) cout<<-1<<endl;
    else{
        sort(ans.begin(),ans.end());
        for(auto x:ans) cout<<x<<" ";
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
