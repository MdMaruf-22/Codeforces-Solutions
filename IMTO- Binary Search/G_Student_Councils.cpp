#include<bits/stdc++.h>
using namespace std;
#define int long long

bool chk(vector<int>& vc,int mid,int k){
    int cnt=0;
    for(auto x:vc){
        cnt+= min(x,k);
    }
    return cnt/k < mid;
}
void solve()
{
    int n,k;cin>>k>>n;
    vector<int> vc(n);       
    for(int i=0;i<n;i++) cin>>vc[i];
    int lo = 0, hi = 1e9/(k+1);
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (chk(vc, mid, k)) {
            hi=mid;
        } else {
            lo = mid+1;
        }
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
