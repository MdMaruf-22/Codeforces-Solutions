#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    cout<<2;
    for(int i=1;i<n;i++){
        cout<<9;
    }
    cout<<endl;
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
