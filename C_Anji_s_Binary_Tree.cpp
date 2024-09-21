#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 3e5+10;
struct Node
{
    char c;
    int left_child;
    int right_child;
};

vector<Node> graph(N);

int dfs(int vertex) {
    int left = graph[vertex].left_child;
    int right = graph[vertex].right_child;
    char dir = graph[vertex].c;
    if (left == 0 && right == 0) return 0;
    int left_min,right_min;
    int cng = 0;
    if(left!=0) {
        if(dir=='R' || dir=='U') cng++; 
        left_min = dfs(left) + cng;
    }
    cng = 0;
    if(right!=0) {
        if(dir=='L' || dir=='U') cng++;
        right_min = dfs(right) + cng;
    }
    return min(left_min,right_min);
}

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        graph[i].c = s[i-1];
        graph[i].left_child = u;
        graph[i].right_child = v;
    }
    int ans = dfs(1);
    cout<<ans<<endl;
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
