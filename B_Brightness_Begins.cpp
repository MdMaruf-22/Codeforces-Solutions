#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int k;
    cin >> k;
    int lo = k,hi = (sqrtl(k)+1)*(sqrtl(k)+1),ans=-1;       
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; 
        int cntsqr = (sqrtl(mid));
        if (mid - cntsqr == k) {
            ans = mid; 
            hi = mid - 1; 
        } 
        else if (mid - cntsqr < k) lo = mid + 1; 
        else hi = mid - 1;
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
