#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, k;
    cin >> n >> k;
    int lo = max(1LL, n - k + 1),hi=n;
    int sum = (hi * (hi + 1)) / 2 - ((lo - 1) * lo) / 2;
    if (sum % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;  
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
