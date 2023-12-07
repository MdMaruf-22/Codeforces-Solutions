#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<bool> isPrime(N,true);
vector<int> primes;
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

void solve()
{
    int n,k;cin>>n>>k;
    int cnt=0;
    for(int i=0;primes[i]+primes[i+1]<=n;i++){
        int sum = primes[i]+primes[i+1]+1;
        if(isPrime[sum]){
            cnt++;
        }
    }
    if(cnt>=k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    sieve();
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
