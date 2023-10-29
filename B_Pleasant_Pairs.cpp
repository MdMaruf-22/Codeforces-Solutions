#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    vector<int> index(2*n+1,-1);
    for(int i=0;i<n;i++){
        cin>>vc[i];
        index[vc[i]] = i+1;
    }
    
    int ans=0;
    for(int i=3;i<=2*n-1;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0 && j*j!=i){
                int ind1 = index[j];
                int ind2 = index[i/j];
                if(ind1==-1||ind2==-1) continue;
                if(ind1+ind2 == i) ans++;                 
            }
        }
    }
    cout<<ans<<endl;
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
