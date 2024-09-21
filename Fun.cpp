#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n,x;cin>>n>>x;
    //int lm = cbrt(n);
    int cnt=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=min(x-i,n/i);j++){
            if(i+j >=x) break;
            int lm2 = (n- i*j) / (i+j);
            
            if(i+j+lm2>x){
                lm2 = x-i-j;
            }
            if(lm2>0) cnt+=lm2;
        }
    }
    cout<<cnt<<endl;
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
