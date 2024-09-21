#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    if(n%2==0) cout<<-1<<endl;
    else{
        int mid = n/2 + 1;
        for(int i=0;i<n/2+1;i++){
            cout<<mid<<" ";
            mid--;
        }
        mid = n/2 + 1;
        for(int i=mid;i<n;i++){
            cout<<mid<<" ";
            mid++;
        }
    }
    cout<<endl;
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
