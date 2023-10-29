#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<pair<int,int>> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i].first>>vc[i].second;
    sort(vc.begin(),vc.end());
    bool f= false;
    for(int i=0;i<n-1;i++){
        int p1 = vc[i].first;
        int p2 = vc[i+1].first;
        int q1 = vc[i].second;
        int q2 = vc[i+1].second;
        if(p1<p2 && q1>q2){
            f=true;
            break;
        }
    }
    if(f) cout<<"Happy Alex"<<endl;
    else cout<<"Poor Alex"<<endl;
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
