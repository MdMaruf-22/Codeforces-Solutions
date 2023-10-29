#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > mx) {
            mx = x;
        }
        mp[x]++;
    }
    for (int i = 1; i<= mx; i++) {
        if (mx % i == 0) {
            mp[i]--;
            //mp[mx / i]--;
        }
    }
    int num = mx;
    for(auto x:mp){
        if(x.second) num = x.first;
    }
    cout<<mx<<" "<<num<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
