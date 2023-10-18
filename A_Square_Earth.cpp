#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
bool vis[N][N];
int level[N][N];
void resetVisArray(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            vis[i][j] = false;
            level[i][j]=0;
        }
    }
}
int bfs(int n,int x1,int y1,int x2,int y2){
    queue<pair<int,int>> q;
    q.push({x1,y1});
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};

    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        vis[x][y] = true;
        if (x == x2 && y == y2) {
            break;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>n || ny<0 || ny>n || vis[nx][ny]) continue;
            q.push({nx,ny});
            vis[nx][ny]=true;
            level[nx][ny] = level[x][y]+1;
        }
    }
    return level[x2][y2];
}

void solve()
{
    int n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    if(x1==x2){
        int ans = bfs(n,x1,y1,x2,y2);
        cout<<ans<<endl;
        return;
    }
    if(y1==y2 && y1==n){
        int ans = bfs(n,x1,y1,x2,y2);
        cout<<ans<<endl;
        return;
    }
    if(y1==n){
        int dis1 = bfs(n,x1,y1,0,n);
        resetVisArray(n);
        if(x2==0) dis1+= (n-y2);
        else dis1+=  (n + x2 + y2);
        int dis2 = bfs(n,x1,y1,n,n);
        resetVisArray(n);
        if(x2==n) dis2+= (n-y2);
        else dis2+= (n + (n-x2) + y2);
        cout<<min(dis1,dis2)<<endl;
        return;
    }
    if(y2==n){
        int dis1 = bfs(n,x2,y2,0,n) ;
        resetVisArray(n);
        if(x1==0){
            dis1+=(n-y1);
        }
        else dis1+= n + x1 + y1;
        int dis2 = bfs(n,x2,y2,n,n);
        resetVisArray(n);
        if(x1==n){
            dis2 += (n-y1);
        }
        else dis2 += n + (n-x1) + y1;
        cout<<min(dis1,dis2)<<endl;
        return;
    }
    int ans1 = bfs(n,x1,0,x2,0);
    resetVisArray(n);
    ans1+=(y1+y2);
    int ans3 = bfs(n,x1,n,x2,n);
    resetVisArray(n);
    ans3+=(n-y1+n-y2);
    cout<<min(ans1,ans3)<<endl;
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
