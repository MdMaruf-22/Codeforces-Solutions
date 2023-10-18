#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10;
int ax, ay, bx, by, cx, cy;
int n;
vector<vector<bool>> q_move(N, vector<bool>(N));
vector<vector<bool>> vis(N, vector<bool>(N));
bool dfs(int x, int y)
{
    if (x == cx - 1 && y == cy - 1) return true;
    if (x < 0 || x >= n || y < 0 || y >= n || q_move[x][y] || vis[x][y]) return false;
    vis[x][y]=true;
    if (dfs(x-1, y)) return true;
    if (dfs(x+1, y)) return true;
    if (dfs(x, y-1)) return true;
    if (dfs(x, y+1)) return true;
    if (dfs(x-1, y-1)) return true;
    if (dfs(x-1, y+1)) return true;
    if (dfs(x+1, y-1)) return true;
    if (dfs(x+1, y+1)) return true;
    return false;
}

void markQueen(int x, int y)
{
    q_move[x][y] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != x)
            q_move[i][y] = true;
        if (i != y)
            q_move[x][i] = true;
        if (x - i >= 0 && y + i < n)
            q_move[x - i][y + i] = true;
        if (x + i < n && y + i < n)
            q_move[x + i][y + i] = true;
        if (x - i >= 0 && y - i >= 0)
            q_move[x - i][y - i] = true;
        if (x + i < n && y - i >= 0)
            q_move[x + i][y - i] = true;
    }
}

void solve()
{
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    markQueen(ax - 1, ay - 1);
    bool sex = dfs(bx - 1, by - 1);
    if (sex)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
