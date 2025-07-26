#include<bits/stdc++.h>
using namespace std;
#define double long double
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
vector<vector<int>> tree; 
vector<bool> visited;

double dfs(int node, int parent) {
    double sum = 0;
    visited[node] = true;
    for (int child : tree[node]) {
        if (child != parent) {
            sum += dfs(child, node) + 1;
        }
    }
    if (sum) sum =  sum / (tree[node].size() - (parent != -1));
    return sum;
}
void solve()
{   
    int n;cin>>n;
    tree.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i < n; ++i) {
        int u,v;cin>>u>>v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    double ans = dfs(0, -1);
    cout<<fixed<<setprecision(10)<<ans<<endl;
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
