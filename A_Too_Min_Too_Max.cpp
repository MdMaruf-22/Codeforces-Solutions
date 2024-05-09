#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
    }
    sort(vc.begin(),vc.end());
    int sum = abs(vc[0]-vc[n-1])+abs(vc[1]-vc[n-2]);
    cout<<2*sum<<endl;
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
