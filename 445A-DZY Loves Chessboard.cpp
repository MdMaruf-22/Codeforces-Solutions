#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3;
char arr[N][N];
bool vis[N][N];
void dfs(int i,int j,int n,int m,char color){
    
    if(i<0 || i>n || j<0 || j>m || arr[i][j]!='.') return;
    vis[i][j]=true;
    arr[i][j] = color;
    if(color=='W') color='B';
    else color='W';
    dfs(i+1,j,n,m,color);
    dfs(i-1,j,n,m,color);
    dfs(i,j-1,n,m,color);
    dfs(i,j+1,n,m,color);
}

void solve()
{
    int n,m;cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            vis[i][j]=false;
        }
    }
    char color = 'W';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.' && !vis[i][j]){
                dfs(i,j,n,m,color);
            }
        }
    }
    //dfs(0,0,n,m,'W');
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
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
