#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcnt(x)
#define cnt_trailing_zero_in_binary(x) __builtin_ctz(x)
#define cnt_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) cin >> vc[i];
    int cnt = 0;
    unordered_map<int, int> r;
    for (int j = 1; j < n; j++) {  
        r[vc[j]]++;
    }
    for (int i = 1; i < n - 1; i++) {  
        r[vc[i]]--;
        unordered_map<int, int> l;
        for (int k = 0; k < i; ++k) {  
            if (vc[k] == -vc[i]) {  
                for (int j = i + 1; j < n; j++) { 
                    if (vc[j] != vc[k] && vc[j] != vc[i]) {
                        cnt++;
                    }
                }
            }
            l[vc[k]]++;
        }
    }
    
    cout << cnt << endl;
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
