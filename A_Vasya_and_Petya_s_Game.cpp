#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
vector<bool> isPrim(N,true);
vector<int> primes;
void sieve(){
    isPrim[0]=isPrim[1]=false;
    for(int i=2;i*i<N;i++){
        if(isPrim[i]){
            for(int j=2*i;j<N;j+=i){
                isPrim[j]=false;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(isPrim[i]) primes.push_back(i);
    }
}
void solve()
{
    int n;cin>>n;
    int ind=0;
    vector<int> vc;
    while(ind<primes[ind]){
        int prime = primes[ind];
        for(int i=prime;i<=n;){
            vc.push_back(i);
            i*=prime;
        }
        ind++;
    }
    cout<<vc.size()<<endl;
    for(auto x:vc) cout<<x<<" ";
    cout<<endl;
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
