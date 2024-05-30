#include<bits/stdc++.h>
using namespace std;
#define int long long
int lowerBound(vector<int>& vc,int target){
    int lo=0,hi=vc.size();
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(vc[mid]<target) lo=mid+1;
        else hi=mid;
    }
    return lo;
}
int upperBound(vector<int>& vc,int target){
    int lo=0,hi=vc.size();
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(vc[mid]<=target) lo=mid+1;
        else hi=mid;
    }
    return lo;
}

void solve()
{
    int n,q;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        int lower = lowerBound(vc,l);
        int upper= upperBound(vc,r);
        int ans = upper - lower;
        cout<<ans<<" ";
    }
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
