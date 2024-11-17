#include <bits/stdc++.h>
using namespace std;

#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];

    map<int, pair<int, int>> mp; 

    int ind = 0, current_gcd = vc[0]; 
    for (int i = 1; i < n; i++)
    {
        if (__gcd(current_gcd, vc[i]) != 1)
        {
            current_gcd = __gcd(current_gcd, vc[i]);
            ind = i; 
        }
    }
    
    mp[2] = {current_gcd, ind + 1}; 

    for (int i = 1; i < n; i++)
    {
        if (mp.count(vc[i - 1]) && mp[vc[i - 1]].second > i)
        {
            int gcd = vc[i], last_ind = ind; 
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(gcd, vc[j]) != 1)
                {
                    gcd = __gcd(gcd, vc[j]);
                    last_ind = j; 
                }
                int mx = max(mp[i].second, last_ind - i + 1);
                mp[i] = {gcd, last_ind + 1};
            }
            cout << mp[i].second << " "; 
        }
    }
    for(auto x:mp) cout<<x.second.second<<" ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
