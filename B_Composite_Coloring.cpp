#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
vector<int> color(N,-1);
vector<int> primes;
vector<bool> isPrime(N,true);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=1;i<N;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}
void solve()
{   
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
        color[i]=-1;
    }
    int ind=0,clr=1,fck=n;
    while(fck){
        int prim = primes[ind];
        bool f = false;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vc[i]%prim==0 && color[i]==-1){
                color[i]=clr;
                cnt++;
                f=true;
            }
        }
        fck-=cnt;
        if(f) clr++;
        ind++;
    }
    cout<<clr-1<<endl;
    for(int i=0;i<n;i++) cout<<color[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}
