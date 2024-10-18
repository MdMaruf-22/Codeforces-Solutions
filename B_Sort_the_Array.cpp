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
    for (int i = 0; i < n; i++) cin >> vc[i];
    
    int l = 0, r = n - 1;
    while (l < n - 1 && vc[l] <= vc[l + 1]) l++;
    if (l == n - 1) {
        cout<<"yes"<<endl<<1<<" "<<1<<endl;
        return;
    }
    while (r > 0 && vc[r] >= vc[r - 1]) r--;
    reverse(vc.begin() + l, vc.begin() + r + 1);
    if (is_sorted(vc.begin(), vc.end())) {
        cout << "yes\n" << l + 1 << " " << r + 1 << endl;
    } 
    else cout << "no"<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
