#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    for (int x = 1; x <= 16; x++) {
        int pow_val = 1;
        for (int i = 0; i < x; i++) {
            pow_val *= x;
        }
        
        if (pow_val == n) {
            cout << x << endl;
            return;
        }
    }
    cout << -1 << endl;
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
