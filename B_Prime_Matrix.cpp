#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
vector<bool> isPrime(N,true);
map<int,int> mp;
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<N;j+=i) isPrime[j]=false;
        }
    }
    for (int i = 1; i < N; i++) {
        if (isPrime[i]) {
            mp[i] = i;
        } else {
            int nextPrime = i + 1;
            while (!isPrime[nextPrime]) {
                nextPrime++;
            }
            mp[i] = nextPrime;
        }
    }
}
void solve()
{
    int n,m;cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int res = 0;
        for(int j=0;j<m;j++){
            res += abs(arr[i][j]-mp[arr[i][j]]);
        }
        ans = min(res,ans);
    }
    for(int j=0;j<m;j++){
        int res = 0;
        for(int i=0;i<n;i++){
            res += abs(arr[i][j]-mp[arr[i][j]]);
        }
        ans = min(res,ans);
    }
    cout<<ans<<endl;
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
