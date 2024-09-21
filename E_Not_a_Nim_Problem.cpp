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
const int N = 1e7+10;
vector<int> primes,grundy_numbers(N,-1);

bool chk_prime(int a) {
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
vector<int> get_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
void calculate_grundy(){
    for(int i=0;i<N;i+=2) grundy_numbers[i] = 0;
    grundy_numbers[1] = 1;
    for (int i = 1; i < primes.size(); i++) {
        for (int j = primes[i]; j < N; j += primes[i] * 2) {
            if (grundy_numbers[j] == -1) {
                grundy_numbers[j] = i + 1;
            }
        }
    }
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
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int mex = 0;
    for(int i=0;i<n;i++) mex^=grundy_numbers[vc[i]];
    if(mex) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes = get_primes(N);
    calculate_grundy();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}