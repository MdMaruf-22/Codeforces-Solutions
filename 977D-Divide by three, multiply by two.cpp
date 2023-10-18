#include <bits/stdc++.h>
using namespace std;
#define int long long
// const int N = 1e5+10;
//  vector<int> tree[N];
//  vector<bool> vis(N);
deque<int> dq;

map<int, bool> mp, vis;
int n;
void bfs(int vertex)
{
    queue<int> cal;
    cal.push(vertex);
    mp[vertex] = true;
    dq.push_back(vertex);
    while (!cal.empty())
    {
        int val = cal.front();
        cal.pop();
        if (vis[val * 3] && !mp[val * 3])
        {
            dq.push_front(val * 3);
            cal.push(val * 3);
            mp[val * 3] = true;
        }
        if (val % 2 == 0 && vis[val / 2] && !mp[val / 2])
        {
            dq.push_front(val / 2);
            cal.push(val / 2);
            mp[val / 2] = true;
        }
        if (vis[val * 2] && !mp[val * 2])
        {
            dq.push_back(val * 2);
            cal.push(val * 2);
            mp[val * 2] = true;
        }
        if (val % 3 == 0 && vis[val / 3] && !mp[val / 3])
        {
            dq.push_back(val / 3);
            cal.push(val / 3);
            mp[val / 3] = true;
        }
    }
}
void solve()
{
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        vis[vc[i]] = true;
    }
    int vertex = *min_element(vc.begin(), vc.end());
    bfs(vertex);
    for (auto x : dq)
        cout << x << " ";
    cout << endl;
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
