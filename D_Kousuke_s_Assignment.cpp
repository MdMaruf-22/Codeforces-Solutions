#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    map<int, int> mp;
    int sum = 0;
    int ans = 0;
    mp[0] = 1; 
    for (int i = 0; i < n; i++) {
        sum += vc[i];
        if (mp.count(sum)) {
            ans++;
            mp.clear();  
            sum = 0;  
            mp[0] = 1;  
        }
        mp[sum]++;
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
