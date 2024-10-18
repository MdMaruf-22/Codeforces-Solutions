#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    int cnt = 0;

    for (char ch : s) {
        if (ch == '(') st.push(ch);
        else {
            if (!st.empty()) st.pop();
            else cnt++;
            
        }
    }

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
