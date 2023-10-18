#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    vector<int> vc(m);
    for(int i=0;i<m;i++) cin>>vc[i];
    vector<int> freq(n+m+1,0),del(n+1,-1);
    int rem=n;
    for(int i=0;i<m;i++){
        freq[vc[i]]++;
        if(freq[vc[i]]==1){
            del[rem]=i+1;
            rem-=1;
            if(rem==0) break;
        }
    }
    for(int i=1;i<=n;i++) cout<<del[i]<<" "; 
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
