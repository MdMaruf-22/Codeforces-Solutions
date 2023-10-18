#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    reverse(arr,arr+n);
    map<int,int> mp;
    vector<int> vc;
    for(int i=0;i<n;i++){
        if(mp[arr[i]]==0){
            vc.push_back(arr[i]);
            mp[arr[i]]++;
        }
        else break;
    }
    cout<<n-vc.size()<<endl;
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
