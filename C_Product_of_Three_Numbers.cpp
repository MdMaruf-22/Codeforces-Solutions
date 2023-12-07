#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    unordered_map<int,int> mp;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            a = i;
            n/=i;
            break;
        }
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0 && i!=a && i!=b){
            c=i;
            n/=i;
            break;
        }
    }
    if(n>1 && n!=a && n!=c) b=n; 
    if(a==INT_MAX ||b==INT_MAX ||c==INT_MAX) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
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
