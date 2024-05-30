#include<bits/stdc++.h>
using namespace std;
#define int long long


bool binarySearch(vector<int>& vc,int target){
    int low = 0,high = vc.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(vc[mid]==target) return true;
        else if(vc[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

void solve()
{
    int n,k;cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    while(k--){
        int target;cin>>target;
        bool chk = binarySearch(vc,target);
        if(chk) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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
