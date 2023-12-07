#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    int sum = (k*k);
    if(sum>n){
        cout<<"NO"<<endl;
        return;
    }
    if(n%2!=k%2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
