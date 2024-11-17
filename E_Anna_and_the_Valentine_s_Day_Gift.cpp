#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];

    vector<int> cnt(n, 0);
    int ttldigit = 0; 
    for (int i = 0; i < n; i++)
    {
        string s = vc[i];
        
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (s[j] == '0')
                cnt[i]++;
            else
                break; 
        }
        ttldigit += s.size() - cnt[i]; 
    }
    sort(cnt.rbegin(), cnt.rend());
    for (int i = 1; i < n; i+=2){
        ttldigit += cnt[i];
    }
    if (ttldigit - 1 >= m)
        cout << "Sasha"<<endl;
    else
        cout << "Anna"<<endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
