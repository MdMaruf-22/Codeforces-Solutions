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
    
    vector<string> vc(n);  
    for (int i = 0; i < n; ++i) cin >> vc[i]; 
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (vc[i][j] == '#') ans.push_back(j+1); 
        }
    }
    for(auto x:ans) cout<<x<<" ";
    cout << endl; 
    
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
