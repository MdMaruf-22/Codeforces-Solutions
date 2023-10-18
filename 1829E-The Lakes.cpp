#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int arr[N][N];
bool vis[N][N];
int ans=0;
void dfs(int i,int j,int n,int m){
    if(i<0 || i>n || j<0 || j>m ||arr[i][j]==0 || vis[i][j]) return;
    vis[i][j] = true;
    ans+=arr[i][j];
    dfs(i-1,j,n,m);
    dfs(i+1,j,n,m);
    dfs(i,j-1,n,m);
    dfs(i,j+1,n,m);
}


void solve()
{   
    ans=0;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=0;
            vis[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int mn = 0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]!=0 && !vis[i][j]){
                dfs(i,j,n,m);
                mn = max(ans,mn);
                ans=0;
            }
        }
    }
    //dfs(i,j,n,m);
    cout<<mn<<endl;
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
