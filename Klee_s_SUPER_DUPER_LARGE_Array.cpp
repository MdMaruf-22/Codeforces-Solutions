#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int countSum(int k, int i) {
    return i * (2 * k + i - 1) / 2;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = n * (2 * k + n - 1) / 2;
    int left = 1, right = n ,ans = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int firstsum = countSum(k, mid);
        int x = abs(2 * firstsum - sum);
        ans = min(ans, x);
        if (2 * firstsum < sum) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
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
