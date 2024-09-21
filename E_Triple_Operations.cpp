#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int N = 2e5+10;
vector<int> pre(N);

//Curretn er maire c*diiiiiiiiiiiiiiiiiiiiiiii
void preprocess() {
    pre[0] = 0;  
    for (int i = 1; i <= N; i++) {
        int num = i;
        int cnt = 0;
        while (num > 0) {
            num /= 3;  
            cnt++;  
        }

        pre[i] = cnt;
    }
}

void solve() {
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += pre[i];
    }

    cout << ans + pre[l] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    preprocess();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
