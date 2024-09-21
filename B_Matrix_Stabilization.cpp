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
const int MAX_ROWS = 101;
const int MAX_COLS = 101;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool vis = false;
int fck(int mat[][MAX_COLS], int n, int m, int row, int col)
{
    int mx = 0;
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
        {
            mx = max(mx, mat[newRow][newCol]);
        }
    }

    return mx;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int mat[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        int mx = fck(mat, n, m, i, j);
        vis = false;
        for (int k = 0; k < 4; k++)
        {
            int newI = i + dx[k];
            int newJ = j + dy[k];

            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m)
            {
                if (mat[i][j] <= mat[newI][newJ])
                {
                    vis = true;
                    break;
                }
            }
        }
        if (!vis) mat[i][j] = mx;
        
    }
}
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
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