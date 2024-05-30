#include<bits/stdc++.h>
using namespace std;
#define int long long
bool chk(vector<int>& vc,double mid,int k){
    int pieces = 0;
    for (int length : vc) {
        pieces += (length / mid);
    }
    return pieces>=k;
}

void solve()
{
    int n,k;cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    double lo = 0,hi = *max_element(vc.begin(),vc.end());
    while(hi-lo>1e-7){
        double mid = lo + (hi-lo)/2;
        if(chk(vc,mid,k)) lo=mid;
        else hi=mid;
    }
    cout << fixed << setprecision(6) << lo << endl;
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
