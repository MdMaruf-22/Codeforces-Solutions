#include<bits/stdc++.h>
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

        for (int i = 0; i < n; i++) {
            cin >> vc[i];
        }

        bool flag = false;
        for (int k = vc[0] - 1; k <= vc[n-1] + 1; k++) {
            bool sck = true;

            for (int i = 0; i < n; i++) {
                int dist = abs(k - vc[i]);
                for (int j = 0; j < n; j++) {
                    if (i != j && abs(vc[j] - vc[i]) <= dist) {
                        sck = false;
                        break;
                    }
                }
                if (!sck) break;
            }

            if (sck) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        
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
