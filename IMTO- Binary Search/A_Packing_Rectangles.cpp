#include<bits/stdc++.h>
using namespace std;
#define int long long

bool chk(int mid,int a,int b,int n){
    int side1 = mid/a;
    int side2 = mid/b;
    int sq = side1 * side2;
    return sq >= n;
}


void solve()
{
    int a,b,n;cin>>a>>b>>n;
    int lo=0,hi=1e10;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(!chk(mid,a,b,n)){
            lo = mid+1;
        }
        else hi=mid;
    }
    cout<<hi<<endl;
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
