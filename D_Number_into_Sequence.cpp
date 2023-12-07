#include<bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
void solve()
{
    int n;cin>>n;
    if(prime(n)){
        cout<<1<<endl;
        cout<<n<<endl;
        return;
    }
    double dt = log2(n*1.00);
    if(dt == (int)dt){
        cout<<(int)dt<<endl;
        while(n!=1){
            n/=2;
            cout<<2<<" ";
        }
        cout<<endl;
        return;
    }
    int k=n;
    map<int,int> mp;
    for(int i=2;i*i<=n;i++){
        int cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        mp[cnt]=i;
    }
    int ttl,div;
    for(auto x:mp){
        ttl = x.first;
        div = x.second;
    }
    vector<int> vc;
    while(ttl--){
        vc.push_back(div);
        k/=div;
    }
    int fck = vc.back();
    vc.pop_back();
    vc.push_back(k*fck);
    cout<<vc.size()<<endl;
    for(auto x:vc) cout<<x<<" ";
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
