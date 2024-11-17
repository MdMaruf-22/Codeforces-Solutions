#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if (s[0] == '1' or s[n - 1] == '1') {
    cout << "YES"<<endl;
    return;
  }
  for (int i = 1; i  < n; i++) {
    if (s[i-1] == '1' and s[i ] == '1') {
      cout << "YES"<<endl;
      return;
    }
  }
  cout << "NO"<<endl;
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
