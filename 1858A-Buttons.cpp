
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b,c;cin>>a>>b>>c;
    if(c%2==0){
        if(a>b) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    else{
        if(b>a) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
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
