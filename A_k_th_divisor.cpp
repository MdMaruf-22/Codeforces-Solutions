#include<bits/stdc++.h>
using namespace std;
#define int long long
bool sieve(int n){
    if(n<2) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
void solve()
{
    int n,k;cin>>n>>k;
    int cnt=0,flag;
    if(sieve(n) && k==2){
        cout<<n<<endl;
        return;
    }
    for(int i=1;i*i<=n;i++){
        if(n%i==0){ 
            cnt++;
            if(cnt==k){
                cout<<i<<endl;
                return;
            }
        }
        flag=i;
    }
    if(k>(cnt*cnt)){
        cout<<-1<<endl;
        return;
    }
    int val = sqrt(n);
    if(val*val == n) flag-=1;
    for(int i=flag;i>=1;i--){
        if(n%i==0){
            cnt++;
            if(cnt==k){
                cout<<n/i<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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
