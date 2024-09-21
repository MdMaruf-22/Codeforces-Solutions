#include <iostream>
#include <vector>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
int gcdExtended(int a, int b, int* x, int* y);

//extended euclidean
int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    int res = (x % M + M) % M;
    return res;
    
}
int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    int su = 0;
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    for(int i=0;i<n;i++) su = (su % MOD + vc[i] % MOD)%MOD;
    //int sumsq = (su*su)%MOD;
    int fck = 0;
    for (int i = 0; i < n; i++) fck = (MOD + (fck % MOD) + (((su - vc[i]) % MOD) * (vc[i] % MOD)) % MOD) % MOD;
    //int sum = (sumsq - fck + MOD) % MOD / 2 ;
    int cons = (n * (n - 1)) % MOD;
    int inv = modInverse(cons,MOD);
    int ans = (fck * inv) % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
