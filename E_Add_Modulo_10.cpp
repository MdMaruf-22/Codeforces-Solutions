#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    bool f = true;
    for(int i=0;i<n;i++){
        cin>>vc[i];
        if(vc[i]%10==0) f=false;
    }
    // if(!f){
    //     cout<<"No"<<endl;
    //     return;
    // }
    for(int i=0;i<n;i++){
        while(vc[i]%10!=0 && vc[i]%10!=2) vc[i] = vc[i] + vc[i]%10;
        if(vc[i]%10==2) vc[i]%=20;
    }
    for(int i=1;i<n;i++){
        if(vc[i-1]!=vc[i]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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
