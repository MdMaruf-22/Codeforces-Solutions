#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++) arr[i]=i;
    arr[n-1]=(arr[n]+arr[n-1])/2;
    //for(int i=0;i<=n;i++ ) cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=n-1;i>=1;i--){
        arr[i-2]=(arr[i]+arr[i-1])/2;
        for(int j=1;j<=n;j++ ) cout<<arr[j]<<" ";
        cout<<endl;
    }
    
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
