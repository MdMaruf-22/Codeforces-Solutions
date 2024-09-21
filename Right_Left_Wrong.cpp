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
    vector<int> pref(n + 1, 0); 

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
        pref[i + 1] = pref[i] + vc[i]; 
    }
    
    string s;
    cin >> s;
    int left = 0, right = n - 1;
    int ans = 0;

    while (left < right) {
        while (left < n && s[left] != 'L') {
            left++;
        }
        while (right >= 0 && s[right] != 'R') {
            right--;
        }

        if (left < right) { 
            ans += pref[right + 1] - pref[left]; 
            left++;
            right--;
        }
    }
    
    cout << ans << endl;
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
