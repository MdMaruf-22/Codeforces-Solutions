#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    int gcd=vc[1]-vc[0];
    for(int i=1;i<n;i++){
        int dif = vc[i]-vc[i-1];
        gcd = __gcd(gcd,dif);
    }
    if(gcd==0){
        cout<<-1<<endl;
        return;
    }
    cout<<gcd<<endl;
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
