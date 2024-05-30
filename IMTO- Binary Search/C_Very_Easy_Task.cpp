#include<bits/stdc++.h>
using namespace std;
#define int long long

bool chk(int mid,int n,int a,int b){
    int copyA = mid/a;
    int copyB = mid/b;
    int ans = copyA + copyB;
    return ans >= n-1;
}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(n==1){
        cout<<min(a,b)<<endl;
        return;
    }
    int lo = min(a,b),hi = n * max(a,b);
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(chk(mid,n,a,b)) hi=mid;
        else lo=mid+1; 
    }
    cout<<lo +min(a,b) <<endl;
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
