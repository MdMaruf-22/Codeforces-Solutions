#include <bits/stdc++.h>
using namespace std;
#define int long long
void play(string& s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            s[(i + 1) % n] = (s[(i + 1) % n] == 'U' ? 'D' : 'U');
            s[(i + n - 1) % n] = (s[(i + n - 1) % n] == 'U' ? 'D' : 'U');
            s.erase(i, 1);
            break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = true;
    while (true) {
        bool cn = false;
        for (char c : s) {
            if (c == 'U') {
                cn = true;
                break;
            }
        }
        if (!cn) {
            cout << (flag ? "NO" : "YES") << endl;
            return;
        }
        if (flag) {
            play(s);
        } else {
            play(s);
        }
        flag = !flag;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
