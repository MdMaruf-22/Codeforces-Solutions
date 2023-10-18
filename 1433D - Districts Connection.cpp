#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    vector<int> vis(n,false);
    for(int i=0;i<n;i++) cin>>vc[i];
    vis[0]=true;
    int mat=0;
    for(int i=1;i<n;i++){
        if(vc[0]!=vc[i]) mat=i;
    }
    if(mat==0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<n;i++){
        if(vc[0]!=vc[i]){
            cout<<1<<" "<<i+1<<endl;
            vis[i]=true;
        }
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i]) cout<<mat+1<<" "<<i+1<<endl;
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
