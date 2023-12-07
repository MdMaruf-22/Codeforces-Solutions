#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+10;
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
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int cnt=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(vc[i]%2==0) cnt++;
        mp[vc[i]]++;
    }
    if(cnt==2){
        cout<<"YES"<<endl;
        return;
    }
    for(auto x:mp){
        if(x.second>1 && x.first>1){
            cout<<"YES"<<endl;
            return;
        }
    }
    mp.clear();
    for(int i=0;i<n;i++){
        int val=vc[i];
        for(int j=0;primes[j]*primes[j]<=val &&j<primes.size();j++){
            if(val%primes[j]==0){
                mp[primes[j]]++;
                if(mp[primes[j]]>1){
                    cout<<"YES"<<endl;
                    return;
                }
                while(val%primes[j]==0) val/=primes[j];
            }
        }
        if(val>1){
            mp[val]++;
            if(mp[val]>1){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
