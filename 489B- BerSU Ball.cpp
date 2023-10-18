#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n;
    vector<int> boy(n);
    for(int i=0;i<n;i++) cin>>boy[i];
    
    cin>>m;
    vector<int> girl(m);
    for(int i=0;i<m;i++) cin>>girl[i];
    sort(boy.begin(),boy.end());sort(girl.begin(),girl.end());
    int b=0,g=0;
    int nct=0;
    while(true){
        if(b==boy.size()) break;
        if(g==girl.size()) break;
        int sub = abs(boy[b]-girl[g]);
        if(sub<=1){
            nct++;
            b++;
            g++;
        }
        else{
            if(boy[b]<girl[g]) b++;
            else g++;
        }
    }
    cout<<nct<<endl;
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
