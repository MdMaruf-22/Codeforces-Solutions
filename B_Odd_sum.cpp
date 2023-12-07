#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n),pos,neg;
    for(int i=0;i<n;i++){
        cin>>vc[i];
        if(vc[i]>=0) pos.push_back(vc[i]);
        else neg.push_back(vc[i]);
    }
    int sum=0;
    for(auto x:pos) sum+=x;
    if(sum%2){
        cout<<sum<<endl;
        return;
    }
    sort(neg.rbegin(),neg.rend());
    sort(pos.begin(),pos.end());
    int k=INT_MAX;
    for(auto x:pos){
        if(x%2){
            k=x;
            break;
        }
    }
    int val;
    bool f=false;
    for(auto x:neg){
        if(abs(x)%2){
            val=abs(x);
            f=true;
            break;
        }
    }
    if(!f) sum-=k;
    //cout<<sum<<endl;
    else sum-=min(val,k);
    cout<<sum<<endl;
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
