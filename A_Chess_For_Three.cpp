#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int sum = a+b+c;
    if(sum%2!=0){
        cout<<-1<<endl;
        return;
    }
    int ans= min(sum/2,(a+b)/2);
    cout<<ans*2<<endl;
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
