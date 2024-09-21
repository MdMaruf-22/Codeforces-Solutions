#include <bits/stdc++.h>
using namespace std;

#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
#define read(v, n)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define print(v)           \
    for (auto &el : v)     \
        cout << el << ' '; \
    cout << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const int mod = 1e9 + 7;

bool is_prime(int a)
{
    if (a <= 1)
    {
        return false;
    }
    if (a <= 3)
    {
        return true;
    }
    if (a % 2 == 0 || a % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= a; i += 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    if (b > a)
        return gcd(b, a);
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int power(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2) % mod) * (power(x, y / 2) % mod)) % mod;
    else
        return ((((x % mod) * ((power(x, y / 2) % mod))) % mod * (power(x, y / 2) % mod)) % mod) % mod;
}

int nCr(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

int ti = 0;
void dfs(int vertex, int parent, vector<int> &tin, vector<int> &lnk, vector<vector<int>> &graph, map<pair<int, int>, int> &mp, vector<int> &conct)
{
    tin[vertex] = lnk[vertex] = ti += 1; 
    for (int to : graph[vertex])
    {
        if (to == parent)
            continue;
        if (tin[to] != 0)
        {
            lnk[vertex] = min(lnk[vertex], tin[to]);
        }
        else
        {
            dfs(to, vertex, tin, lnk, graph, mp, conct);
            lnk[vertex] = min(lnk[vertex], lnk[to]);
            if (lnk[to] > tin[vertex])
            {
                mp[{vertex, to}] = conct[to];
                mp[{to, vertex}] = conct[to];
            }
            else
            {
                conct[vertex] += conct[to];
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> tin(n + 1, 0), lnk(n + 1, 0), conct(n + 1, 1);
    map<pair<int, int>, int> mp;

    dfs(1, -1, tin, lnk, graph, mp, conct);

    int ttl = n * (n - 1) / 2;
    int mn = ttl;

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        int u = it->first.first;
        int v = it->first.second;
        int size = it->second;
        if (u < v)
        {
            int cnt1 = size;
            int cnt2 = n - size;
            int pr = cnt1 * (cnt1 - 1) / 2 + cnt2 * (cnt2 - 1) / 2;
            mn = min(mn, pr);
        }
    }

    cout << mn << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}