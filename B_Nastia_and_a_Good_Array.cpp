#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9+7;
vector<bool> isPrime(N,true);
vector<int> primes;
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=N;j+=i) isPrime[j]=false;
        }
    }
    for(int i=0;i<=N;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}
void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int mx = *max_element(vc.begin(),vc.end());
    int prime = N;
    
    vector<pair<pair<int,int>,pair<int,int>>> pr;
    for(int i=1;i<n;i+=2){
        int val1 = vc[i-1];
        int val2 = vc[i];
        if(val1<val2){
            pr.push_back({{i,i+1},{val1,prime}});
        }
        else pr.push_back({{i,i+1},{val2,prime}});
    }
    cout<<pr.size()<<endl;
    for(auto x:pr){
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second.first<<" "<<x.second.second<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //sieve();
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}
