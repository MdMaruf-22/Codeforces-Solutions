#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    
    int a[n], p[n];
    bool visb[n], viss[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        p[i] = x - 1;
        visb[i] = viss[i] = false;
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    b--;
    s--;

    vector<int> cnt1, cnt2;
    for(int i = 0; i < n; i++) viss[i] = visb[i] = false;
    while(visb[b] == false){
        cnt1.push_back(a[b]);
        visb[b] = true;
        b = p[b];
    }
    while(viss[s] == false){
        cnt2.push_back(a[s]);
        viss[s] = true;
        s = p[s];
    }
    int xa = 0, xb = 0, xc = 0, xd = 0;
    for(int i = 0; i < (int)cnt1.size(); i++){
        if(i >= k) break;
        if(xa < xc + cnt1[i] * (k - i)) xa = xc + cnt1[i] * (k - i);
        xc += cnt1[i];
    }
    for(int i = 0; i < (int)cnt2.size(); i++){
        if(i >= k) break;
        if(xb < xd + cnt2[i] * (k - i)) xb = xd + cnt2[i] * (k - i);
        xd += cnt2[i];
    }
    int op;
    if(xa == xb) op = 1;
    else{
        if(xa > xb) op = 2;
        else op = 3;
    }
    
    if(op == 1) cout << "Draw\n";
    else if(op == 2) cout << "Bodya\n";
    else cout << "Sasha\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
