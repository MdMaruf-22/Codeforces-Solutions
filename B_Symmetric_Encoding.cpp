#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string b;
    cin >> b;
    string newStr = b;
    sort(newStr.begin(), newStr.end());
    string unq;
    for (char ch : newStr) {
        if (unq.empty() || ch != unq.back()) {
            unq.push_back(ch);
        }
    }

    map<char, char> decode_map;
    int sz = unq.size();
    for (int i = 0; i < sz; ++i) {
        decode_map[unq[i]] = unq[sz - i - 1];
    }
    string s = b;
    for (char& ch : s) {
        ch = decode_map[ch];
    }
    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
