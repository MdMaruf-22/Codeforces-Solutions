#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

vector<tuple<int, int, char>> pr;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n), to(n);
    for (int i = 0; i < n; i++) cin >> vc[i];
    for (int i = 0; i < n; i++) cin >> to[i];
    sort(vc.begin(), vc.end());
    for(int i = n - 1; i >= 0; i--) {
        int pos = -1;
        for (int j = i; j >= 0; j--) { 
            if (to[i] == vc[j]) {
                pos = j;
                break;
            }
        }
        if (pos != -1 && pos != i) {
            int end_pos = min(pos + 1, n);
            int mn = *min_element(vc.begin() + pos, vc.begin() + i + 1);
            if (mn == vc[pos]) {
                pr.emplace_back(pos + 1, i + 1, 'D');
                sort(vc.begin() + pos, vc.begin() + i + 1, greater<int>());
            } else {
                pr.emplace_back(pos + 1, i + 1, 'I');
                sort(vc.begin() + pos, vc.begin() + i + 1);
            }
        }
    }

    cout << pr.size() + 1 << endl;
    cout << 1 << " " << n << " " << 'I' << endl;
    for (auto x : pr) {
        int l, r;
        char c;
        tie(l, r, c) = x;
        cout << l << " " << r << " " << c << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
