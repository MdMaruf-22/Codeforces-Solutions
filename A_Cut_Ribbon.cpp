#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

vector<int> dp;

int calc(int n, int a, int b, int c) {
    if (n == 0) return 0;
    if (n < 0) return INT_MIN; 
    if (dp[n] != -1) return dp[n];
    int first = calc(n - a, a, b, c) + 1;
    int second = calc(n - b, a, b, c) + 1;
    int third = calc(n - c, a, b, c) + 1;
    return dp[n]=max({first, second, third});
}

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp.assign(n + 1, -1);
    int result = calc(n, a, b, c);
    cout << (result < 0 ? 0 : result) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
