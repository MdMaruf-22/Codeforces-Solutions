#include<bits/stdc++.h>
using namespace std;
#define int long long
char mat[20][20][20];
bool vis[20][20][20];
int k,n,m;
int cnt=0;
void dfs(int i,int j,int x){
    if(i<0 || i==k || j<0 || j==n || x<0 || x==m || mat[i][j][x]=='#' || vis[i][j][x]) return;
    vis[i][j][x]=true;
    cnt++;
    dfs(i+1,j,x);
    dfs(i-1,j,x);
    dfs(i,j+1,x);
    dfs(i,j-1,x);
    dfs(i,j,x-1);
    dfs(i,j,x+1);
}


void solve()
{
    
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            for(int x=0;x<m;x++){
                cin>>mat[i][j][x];
            }
        }
    }
    int a,b;cin>>a>>b;
    dfs(0,a-1,b-1);
    cout<<cnt<<endl;
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
