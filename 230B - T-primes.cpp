#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool> isPrime(N,1);
int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    int n;
    cin>>n;
    while(n--){
        long long int x,sq;
        cin>>x;
        sq=sqrt(x);
        if(sq*sq==x && isPrime[sq]) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}
