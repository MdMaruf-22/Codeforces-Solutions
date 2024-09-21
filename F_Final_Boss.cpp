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
    int p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            int m = __gcd(p, k);
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
int binarySearch(vector<pair<int, int>> &vc, int target)
{
    int lo = 0, hi = vc.size();
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (vc[mid].first < target)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}
void solve()
{
    int h, n;
    cin >> h >> n;
    vector<int> vc(n), sx(n);
    read(vc, n);
    read(sx, n);
    vector<pair<int, int>> pr;
    int curr = 0, cnt = 0;
    for (int i = 0; i < n; i++) pr.push_back({curr, i});
    while (h > 0)
    {
        int fck = 0;
        vector<pair<int, int>> nxt;
        int ind = binarySearch(pr, curr);
        for (int i = ind; i < pr.size() && pr[i].first == curr; i++)
        {
            int mar = pr[i].second;
            fck += vc[mar];
            int flo = curr + sx[mar];
            nxt.push_back({flo, mar});
        }
        if (fck == 0){
            if (!pr.empty()) curr = pr[0].first;
            continue;
        }
        h -= fck;
        cnt += fck;
        for (auto x : nxt) pr.push_back(x);
        pr.erase(pr.begin(), pr.begin() + nxt.size());
        sort(pr.begin(), pr.end());
        curr++;
    }
    cout << curr << endl;
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