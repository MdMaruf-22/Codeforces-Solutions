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
    string s;
    cin >> s;

    map<pair<char, char>, int> mp;
    char prev = '1';
    for (char zero : s) {
        mp[{prev, zero}]++;
        prev = zero;
    }

    int zero = mp[{'1', '0'}];  
    int one = mp[{'0', '1'}] + mp[{'1', '1'}];  

    if (zero >= one) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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
