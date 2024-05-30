#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid,vector<int>& vc,int n,int k){
    int cnt = 0;
    for(int i=(n-1)/2;i<n;i++){
        cnt += max(0LL,mid-vc[i]);
    }
    return cnt<=k;
}

int binarySearch(int lo,int hi,vector<int>& vc,int n,int k){
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid,vc,n,k)){
            lo = mid+1;
        }
        else hi = mid;
    }
    return lo;
}
void solve()
{
    int n,k;cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    int ans = binarySearch(0,3e9,vc,n,k);
    cout<<ans-1<<endl;
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
