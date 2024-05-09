#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int cnt=1;
    sort(vc.begin(),vc.end());
    int mid = (n-1)/2;
    for(int i=mid+1;i<n;i++){
        if(vc[i]<=vc[mid]){
            cnt += vc[mid]-vc[i]+1;
        }
    }
    cout<<cnt<<endl;
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
