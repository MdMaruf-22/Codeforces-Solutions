#include<bits/stdc++.h>
using namespace std;
#define int long long


bool chk(vector<int>& vc, int n, int k, int mid) {
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
        if(even<k){
            if(even%2==0 || vc[i]<=mid) even++;
        }
        if(odd<k){
            if(odd%2==1 || vc[i]<=mid) odd++;
        }
    }
    return even>=k || odd>=k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    for(int i = 0; i < n; i++) cin >> vc[i];
    
    int lo = 1, hi = 1e9;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(chk(vc, n, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
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
