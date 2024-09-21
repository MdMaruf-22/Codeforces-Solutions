#include <bits/stdc++.h>
using namespace std;

#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
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
    int p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            int m = __gcd(p, k);
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, bool>> prgrm(n + m + 1);
    vector<pair<int, bool>> test(n + m + 1);
    for(int i=0;i<n+m+1;i++) cin >> prgrm[i].first;
    for(int i=0;i<n+m+1;i++) cin >> test[i].first;
    for(int i=0;i<n+m+1;i++){
        prgrm[i].second = false;
        test[i].second = false;
    }

    int cnt1 = 0, cnt2 = 0;
    int fck = 0, sx = 0;
    
    for (int i = 0; i < prgrm.size(); i++) {
        if (prgrm[i].first > test[i].first && fck <= n) {
            cnt1 += prgrm[i].first;
            fck++;
            prgrm[i].second = true;
        } else if (prgrm[i].first < test[i].first && sx < m) {
            cnt1 += test[i].first;
            sx++;
            prgrm[i].second = false;
        } else if (fck <= n) {
            cnt1 += prgrm[i].first;
            fck++;
            prgrm[i].second = true;
        } else {
            cnt1 += test[i].first;
            sx++;
            prgrm[i].second = false;
        }
    }
    fck = 0;
    sx = 0;
    for (int i = 0; i < prgrm.size(); i++) {
        if (prgrm[i].first < test[i].first && sx <= m) {
            cnt2 += test[i].first;
            sx++;
            test[i].second = false;
        } else if (prgrm[i].first > test[i].first && fck < n) {
            cnt2 += prgrm[i].first;
            fck++;
            test[i].second = true;
        } else if (sx <= m) {
            cnt2 += test[i].first;
            sx++;
            test[i].second = false;
        } else {
            cnt2 += prgrm[i].first;
            fck++;
            test[i].second = true;
        }
    }
    
    for (int i = 0; i < prgrm.size(); i++) {
        int val = 0;
        if (prgrm[i].second) {
            val = cnt1 - prgrm[i].first;
        } else if (!test[i].second) {
            val = cnt2 - test[i].first;
        }
        cout << val << " ";
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