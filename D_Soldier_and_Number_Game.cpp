#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000001;
vector<int> primefactor(N),ttlprimefactors(N);

void sieve(){
    primefactor[0]=primefactor[1]=0;
    for(int i=2;i<=N;i++) primefactor[i]=i; 
    for(int i=2;i<=N;i+=2) primefactor[i]=2;
    for(int i=3;i*i<=N;i+=2){
        if(primefactor[i]==i){
            for(int j=i*i;j<N;j+=(2*i)){
                if(primefactor[j]==j) primefactor[j]=i;
            }
        }
    }
    for(int i=2;i<N;i++) ttlprimefactors[i]=ttlprimefactors[i/primefactor[i]]+1;
    for(int i=2;i<N;i++) ttlprimefactors[i]+=ttlprimefactors[i-1];
}
void solve()
{
    int a,b;
    //cin>>a>>b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",ttlprimefactors[a]-ttlprimefactors[b]);
    //cout<<ttlprimefactors[a]-ttlprimefactors[b]<<endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    sieve();
    int t;
    scanf("%lld",&t);
    while(t--){
        solve();
    }
    return 0;
}

