#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
char arr[N][N];
bool vis[N][N];
int n,m,k;

void dfs(int row,int col){
    if(row<0 || row>=n || col<0 || col>=m || arr[row][col]=='#' || vis[row][col]) return;
    vis[row][col]=true;
    dfs(row-1,col);
    dfs(row+1,col);
    dfs(row,col-1);
    dfs(row,col+1);
    if(k>0){
        arr[row][col]='X';
        k--;
    }
}   


void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int row=-1,col;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                row = i;
                col = j;
                break;
            }
        }
        if(row!=-1) break;
    }
    dfs(row,col);
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
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
