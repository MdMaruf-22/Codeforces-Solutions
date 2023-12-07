#include<bits/stdc++.h>
using namespace std;
#define int long long
bool root(int n){
    int sq = sqrt(n);
    return sq*sq==n?true:false;
}
void solve()
{
    int n;cin>>n;
    int cnt=0;
    for(int i=1;i*i<n;i++){
        if(n%i==0) cnt+=2;
    }
    if(root(n)) cnt++;
    cout<<cnt<<endl;
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
