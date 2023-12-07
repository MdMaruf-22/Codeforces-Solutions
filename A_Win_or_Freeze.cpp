#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4000010;
vector<int>v;
vector<bool> prime(N,true);
void sieve()
{
    v.push_back(2);
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[i]=false;
            }
        }
    }
    for(int i=3;i<N;i+= 2) if(prime[i] == true) v.push_back(i);
}
void solve()
{
    int n;cin>>n;
    if(n==1){
        cout<<1<<endl<<0<<endl;
        return;
    }
    if(prime[n]){
        cout<<1<<endl;
        cout<<0<<endl;
    }
    int sq = sqrt(n);
    if(sq*sq==n && prime[sq]){
        cout<<2<<endl;
        return;
    }
    double d = log2(n*1.00);
    if(d==(int)d){
        cout<<2<<endl;
        return;
    } 
    vector<int> div;
    for(int i=0;v[i]*v[i]<=n && i<v.size();i++){
        while(n%v[i]==0){
            n/=v[i];
            div.push_back(v[i]);
        }
    }
    if(n!=1) div.push_back(n);
    if(div.size()==2){
        cout<<2<<endl;
        return;
    }
    cout<<1<<endl;
    cout<<div[0]<<endl;
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
