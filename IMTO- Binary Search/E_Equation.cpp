#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

bool chk(double n,double mid){
    double val = mid*mid + sqrt(mid);
    return val>=n;
}


void solve()
{
    double n;cin>>n;
    double lo=0,hi=n;
    while(hi-lo>1e-7){
        double mid=(lo+hi)/2;
        if(chk(n,mid)) hi=mid;
        else lo=mid;
    }
    cout<<setprecision(10)<<lo<<endl;
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
