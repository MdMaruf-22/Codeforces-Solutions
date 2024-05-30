#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int>& towers, int val){
    int lo=0,hi=towers.size();
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(towers[mid]>=val) hi=mid;
        else lo = mid+1;
    }
    return lo;
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int currRight = binarySearch(b,a[i]);
        //cout<<currRight<<" ";
        int currLeft = currRight - 1;
        int minDis = INT_MAX;
        if(currRight < m){
            minDis = min (minDis, b[currRight] - a[i]);
        }
        if(currLeft >= 0){
            minDis = min(minDis, a[i] - b[currLeft] );
        }
        ans = max(ans,minDis);
    }
    cout<<ans<<endl;
    //cout<<endl;
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
