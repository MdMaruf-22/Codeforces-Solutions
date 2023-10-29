#include<bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int n){
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    } 
    return true;
}
void solve()
{
    int n;cin>>n;
    if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }
    if(prime(n)){
        cout<<1<<" "<<n-1<<endl;
        return;
    }
    if(n%3==0){
        cout<<n/3<<" "<<(n/3)*2<<endl;
        return;
    }
    int div;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            div=i;
            break;
        }
    }
    int fac = n/div;
    cout<<fac<<" "<<n-fac<<endl;
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
