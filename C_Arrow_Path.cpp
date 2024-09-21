#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 2e5+10;
vector<string> graph(N);
vector<vector<bool>> vis(2,vector<bool>(N,false));
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool dfs(int x,int y,int n){
    if(x==1 && y==n-1) return true;
    vis[x][y] = true;
    if((x+y)%2 == 0){
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx >= 0 && nx < 2 && ny >= 0 && ny < n && !vis[nx][ny]) {
                if (dfs(nx, ny, n)) return true;
            }
        }
    }
    else{
        if(graph[x][y]=='>'){
            if(y+1 < n && !vis[x][y+1]){
                if(dfs(x,y+1,n)) return true;
            }
        }
        else{
            if(y-1>=0 && !vis[x][y-1]){
                if(dfs(x,y-1,n)) return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n;cin>>n;
    cin>>graph[0]>>graph[1];
    for (int i = 0; i < 2; i++) {
        fill(vis[i].begin(), vis[i].begin() + n, false);
    }
    if(dfs(0,0,n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
