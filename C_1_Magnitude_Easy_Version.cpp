#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int calc(int ind,vector<int>& vc,int n,int sum){
    if(ind==n) return sum;
    int first = calc(ind+1,vc,n,sum+vc[ind]);
    int second = calc(ind+1 , vc,n,abs(sum+vc[ind]));
    return max(first,second);
}


void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int sum=0,minus_sum=0;
    for(int i=0;i<n;i++){
        sum+=vc[i];
        if(sum<0){
            minus_sum+=abs(sum);
            sum=0;
        }
    }
    cout<<minus_sum+sum<<endl;
    //int ans = calc(0,vc,n,0);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}