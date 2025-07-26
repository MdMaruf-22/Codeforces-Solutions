#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    int blocks = 0;
    bool in_block = false;

    for (int i = 0; i < n; i++) {
        if (vc[i] != 0) {
            if (!in_block) {
                blocks++;
                in_block = true;
            }
        } else {
            in_block = false;
        }
    }
    if(blocks>2) blocks=2;
    cout << blocks << endl;
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
