#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x;cin>>n>>x;
    int odd=0,even=0;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        if(val%2) odd++;
        else even++;
    }
    if(odd==0){
        cout<<"No"<<endl;
        return;
    }
    if(n==x){
        if(odd%2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
    if(x%2==0){
        if(even==0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    else cout<<"Yes"<<endl;
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
