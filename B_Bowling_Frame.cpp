#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

int chk(int mid , int n ,int m){
    int cnt = mid*(mid+1)/2;
    if(cnt > n + m || (cnt > m && (cnt-m)>n) || (cnt>n && (cnt-n)>m)) return false;
    return true;
}


void solve()
{
    int n,m;cin>>n>>m;
    int lo=0,hi=INT_MAX,ans=0;
    while(lo<=hi){
        int mid= lo + (hi - lo)/2;
        if(chk(mid,n,m)){
            ans=mid;
            lo = mid+1;
        }
        else hi=mid-1;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
