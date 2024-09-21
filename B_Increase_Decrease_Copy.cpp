#include <bits/stdc++.h>
using namespace std;

#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
#define read(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define print(v) for (auto& el : v) cout << el << ' '; cout << endl
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const int mod = 1e9+7;

bool is_prime(int a) {
    if (a <= 1) {
        return false;
    }
    if (a <= 3) {
        return true;
    }
    if (a % 2 == 0 || a % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= a; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    if (b > a)
        return gcd(b, a);
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int power(int x, int y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2) % mod) * (power(x, y / 2) % mod)) % mod;
    else
        return ((((x % mod) * ((power(x, y / 2) % mod))) % mod * (power(x, y / 2) % mod)) % mod) % mod;
}

int nCr(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else
        p = 1;
    return p;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n+1);
    
    read(a,n);
    read(b,n+1);
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);
    }
    
    int last = b[n];
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if ((last >= a[i] && last <= b[i]) || (last >= b[i] && last <= a[i])) {
            flag = true;
            break;
        }
    }
    
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, abs(a[i] - last));
        mn = min(mn, abs(b[i] - last));
    }
    ans += flag ? 1 : (mn + 1);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}