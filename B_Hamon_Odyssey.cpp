#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{       
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int and_v = vc[0];
    for(int i=1;i<n;i++) and_v &= vc[i];
    int cnt = 0; 
    if(and_v>0) cnt = 1;
    else {
        int curr = vc[0];
        for(int i = 0; i < n; i++) {
            curr &= vc[i];
            if(curr == 0) {
                cnt++;
                if (i < n - 1) {
                    curr = vc[i + 1]; 
                }
            }
        }
    }
    cout << cnt << endl;
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
