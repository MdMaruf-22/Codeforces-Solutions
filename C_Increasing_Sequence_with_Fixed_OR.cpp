#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> vc;
    vc.push_back(n);

    for (int i = 0; i < 64; i++) {
        if (n & (1LL << i)) {
            int nxt = n & ~(1LL << i);
            if (nxt != 0) {
                vc.push_back(nxt);
            }
        }
    }
    reverse(vc.begin(), vc.end());
    cout<<vc.size()<<endl;
    for(auto x:vc) cout<<x<<" ";
    cout<<endl;
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
