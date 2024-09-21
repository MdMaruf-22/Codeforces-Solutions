#include <bits/stdc++.h>
using namespace std;

#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcnt(x)
#define cnt_trailing_zero_in_binary(x) __builtin_ctz(x)
#define cnt_leading_zero_in_binary(x) __builtin_clz(x)
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
    int n, k;
    cin >> n >> k;
    int sz = 2 * k;

    vector<int> vc(2 * n);
    unordered_map<int, int> m;

    for (auto &element : vc) cin >> element;

    for (int i = 0; i < n; i++) m[vc[i]]++;

    vector<int> group0, group1, group2;
    for (int i = 1; i <= n; i++) {
        if (m[i] == 0) group0.push_back(i);
        else if (m[i] == 1) group1.push_back(i);
        else group2.push_back(i);
    }

    int cnt = 0;
    vector<int> left, right;
    for (auto x : group2) {
        if (cnt < sz) {
            cnt += 2;
            left.push_back(x);
            left.push_back(x);
        }
    }
    for (auto x : group1) {
        if (cnt < sz) {
            cnt++;
            left.push_back(x);
        }
    }
    cnt = 0;
    for (auto x : group0) {
        if (cnt < sz) {
            cnt += 2;
            right.push_back(x);
            right.push_back(x);
        }
    }
    for (auto x : group1) {
        if (cnt < sz) {
            cnt++;
            right.push_back(x);
        }
    }
    for (int i = 0; i < sz; i++) {
        cout << left[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < sz; i++) {
        cout << right[i] << " ";
    }
    cout << endl;
    
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