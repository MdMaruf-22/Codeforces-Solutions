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
map<int, int> fact(int k)
{
    map<int, int> div;
    for (int i = 1; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            div[i]++;
            if (i != k / i)
            {
                div[k / i]++;
            }
        }
    }
    return div;
}

void solve()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    int ans = 0;
    map<int, int> div = fact(k);
    for (auto it = div.begin(); it != div.end(); it++)
    {
        int divi1 = it->first;
        int cnt1 = it->second;
        if (k % divi1 != 0)
            continue;

        int rem = k / divi1;
        map<int, int> fck = fact(rem);
        for (auto sx = fck.begin(); sx != fck.end(); sx++)
        {
            int divi2 = sx->first;
            int cnt2 = sx->second;
            if (rem % divi2 != 0)
                continue;

            int divi3 = rem / divi2;
            int cnt3 = fck[divi3];

            if (divi1 <= x && divi2 <= y && divi3 <= z)
            {
                int loc = (x - divi1 + 1) * (y - divi2 + 1) * (z - divi3 + 1) * cnt1 * cnt1 * cnt2;
                ans = max(ans, loc);
            }
            if (divi1 <= x && divi3 <= y && divi2 <= z)
            {
                int loc = (x - divi1 + 1) * (y - divi3 + 1) * (z - divi2 + 1) * cnt1 * cnt2 * cnt1;
                ans = max(ans, loc);
            }
            if (divi2 <= x && divi1 <= y && divi3 <= z)
            {
                int loc = (x - divi2 + 1) * (y - divi1 + 1) * (z - divi3 + 1) * cnt1 * cnt1 * cnt2;
                ans = max(ans, loc);
            }
            if (divi2 <= x && divi3 <= y && divi1 <= z)
            {
                int loc = (x - divi2 + 1) * (y - divi3 + 1) * (z - divi1 + 1) * cnt1 * cnt2 * cnt1;
                ans = max(ans, loc);
            }
            if (divi3 <= x && divi1 <= y && divi2 <= z)
            {
                int loc = (x - divi3 + 1) * (y - divi1 + 1) * (z - divi2 + 1) * cnt2 * cnt1 * cnt1;
                ans = max(ans, loc);
            }
            if (divi3 <= x && divi2 <= y && divi1 <= z)
            {
                int loc = (x - divi3 + 1) * (y - divi2 + 1) * (z - divi1 + 1) * cnt2 * cnt1 * cnt1;
                ans = max(ans, loc);
            }
        }
    }
    cout << ans << endl;
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