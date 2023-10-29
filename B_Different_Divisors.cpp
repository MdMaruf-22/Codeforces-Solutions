#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10;
vector<int> isPrime(N,true);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    if (b > a)
        return gcd(b, a);
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
void solve()
{
    int d;cin>>d;
    int f_pr;
    for(int i=d+1;;i++){
        if(isPrime[i]){
            f_pr = i;
            break;
        }
    }
    int s_pr ;
    for(int i=f_pr+d;;i++){
        if(isPrime[i]){
            s_pr=i;
            break;
        }
    }
    int lc = lcm(s_pr,f_pr);
    cout<<lc<<endl;
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
