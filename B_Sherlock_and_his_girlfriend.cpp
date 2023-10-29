#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000+10;
vector<bool> isPrime(N,true);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(isPrime[2]){
            for(int j=i*i;j<=N;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
void solve()
{
    int n;cin>>n;
    if(n==1) cout<<1<<endl<<1<<endl;
    else if(n==2) cout<<1<<endl<<1<<" "<<1<<endl;
    else{
        cout<<2<<endl;
        for(int i=1;i<=n;i++){
            if(isPrime[i+1]) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}
