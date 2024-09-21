#include<bits/stdc++.h>
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

    int sq = sqrt(n);
    if (sq * sq != n) {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < sq; i++) {
        for (int j = 0; j < sq; j++) {
            int ind = i * sq + j;
            if (i == 0 || i == sq - 1 || j == 0 || j == sq - 1) {
                if (s[ind] != '1') {
                    cout << "No" << endl;
                    return;
                }
            } 
            else {
                if (s[ind] != '0') {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    cout << "Yes" << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
