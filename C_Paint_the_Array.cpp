#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) cin >> vc[i];
    int gcdOdd = vc[0], gcdEven = vc[1];
    for (int i = 0; i < n; i++){
        if (i % 2 == 0) gcdOdd = __gcd(gcdOdd, vc[i]);
        else gcdEven = __gcd(gcdEven, vc[i]);
    }
    bool chk1=false,chk2=false;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            if (vc[i] % gcdEven == 0)chk1=true;
        }
        else{
            if (vc[i] % gcdOdd == 0) chk2=true;
        }
    }
    if (!chk1) cout << gcdEven << endl;
    else if (!chk2) cout << gcdOdd << endl;
    else cout<<0<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
