#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    bool flag = false;
    for (char c : s) {
        if (c == 'p') {
            flag = true; 
        }
        if (c == 's' && flag) {
            cout << "NO\n";
            return;
        }
    }

    int pcn = 0, scn = 0, cnt = 0;
    for (auto x : s) {
        if (x == 'p') pcn++;
        else if (x == 's') scn++;
        else cnt++;
    }

    if (pcn == n || scn == n || cnt == n) {
        cout << "YES\n";
    } else if ((pcn && cnt && !scn) || (scn && cnt && !pcn)) {
        cout << "YES\n";
    } else {
        if (scn == 1 && s[0] == 's') {
            cout << "YES\n";
            return;
        }
        if (pcn == 1 && s[n - 1] == 'p') {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
