#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

int longestSubstring(string s, int k)
{
    map<char, int> mp;
    for (auto x : s)
        mp[x]++;
    bool flag = true;
    for (auto x : mp)
    {
        if (x.second < k)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return s.size();
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] < k)
        {
            maxLen = max(maxLen, longestSubstring(s.substr(start, i - start), k));
            start = i + 1;
        }
    }
    maxLen = max(maxLen, longestSubstring(s.substr(start), k));
    return maxLen;
}

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int ans = longestSubstring(s, k);
    cout << ans << "\n";
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
