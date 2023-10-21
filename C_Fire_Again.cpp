#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2001;
int forest[N][N];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    forest[x][y] = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nw_x = x + dx[i];
            int nw_y = y + dy[i];

            if (nw_x > 0 && nw_x <= n && nw_y > 0 && nw_y <= m && forest[nw_x][nw_y]>forest[x][y]+1){
                forest[nw_x][nw_y] = forest[x][y] + 1;
                q.push({nw_x, nw_y});
            }
        }
    }
}

void solve()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            forest[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        bfs(u, v);
    }
    int lastx, lasty;
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mx < forest[i][j])
            {
                mx = forest[i][j];
                lastx = i;
                lasty = j;
            }
        }
    }
    cout << lastx << " " << lasty << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}