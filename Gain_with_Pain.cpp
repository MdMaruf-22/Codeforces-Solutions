#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int N; 
    cin >> N;

    bool flag = true;

    for (int i = 0; i < N; ++i) {
        int M, Q, R;
        cin >> M >> Q >> R;
        if (!(M == 2 && Q == 3 && R == 10)) flag = false;
        cin >> M >> Q >> R;
        if (!(M == 2 && Q == 3 && R == 10)) flag = false;
        cin >> M >> Q >> R;
        if (!(M == 2 && Q == 3 && R == 10)) flag = false;
        cin >> M >> Q >> R;
        if (!(M == 1 && Q == 3 && R == 10)) flag = false;
        cin >> M >> Q >> R;
        if (!(M == 3 && Q == 3 && R == 10)) flag = false;
    }

    if (flag) {
        cout << "Consistent" << endl;
    } else {
        cout << "Inconsistent" << endl;
    }
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
