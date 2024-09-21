#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    string s;
    cin >> s;
    
    if (s.size() < 3 || s[0] != '1' || s[1] != '0' || s[2] == '0') {
        cout << "NO" << endl;
    }
    else if (s.size() == 3 && s[2] == '1') {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
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
