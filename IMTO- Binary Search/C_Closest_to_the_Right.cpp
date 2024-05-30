#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int>& vc,int target){
    int low=0,high=vc.size()-1;
    int ans=vc.size();
    while(low<high){
        int mid = low + (high-low)/2;
        if(vc[mid]<target){
            low = mid+1;
        }
        else{
            ans = mid;
            high=mid-1;
        }
    }
    return ans;
}


void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    while(k--){
        int target;cin>>target;
        int ans = binarySearch(vc,target);
        //cout<<ans<<endl;
        if(ans<n){
            cout<<ans+1<<endl;
        }
        else{
            cout<<n+1<<endl;
        }
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
