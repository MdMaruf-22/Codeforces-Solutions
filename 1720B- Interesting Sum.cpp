#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int ans1=arr[n-1]-arr[0]+arr[n-2]-arr[1];
    int ans2=arr[n-2]-arr[1]+arr[n-1]-arr[0];
    cout<<max(ans1,ans2)<<endl;
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
