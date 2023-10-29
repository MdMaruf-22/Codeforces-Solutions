#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x;cin>>n>>x;
    vector<pair<int, int>> div;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            int a = i;
            int b = x / i;
            if (a != b) {
                div.push_back({a, b});
                div.push_back({b, a});
            } 
            else {
                div.push_back({a, b});
            }
        }
    }
    int cnt=0;
    for(auto x:div){
        if(x.first<=n && x.second<=n) cnt++;
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
