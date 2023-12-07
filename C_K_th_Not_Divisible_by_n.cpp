#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    if(k<n){
        cout<<k<<endl;
        return;
    }
    int dif = (n-1);
    int cal = k/dif;
    int cal2;
    if(cal==1){
        k-=dif;
        if(k==0){
            cout<<n-1<<endl;
            return;
        }
        cout<<n*cal+k<<endl;
        return;
    }
    if(k%dif){
        cal2=cal+1;
        int val = n*cal-cal;
        k-=val;
        cout<<n*cal+k<<endl;    
    }
    else{
        cal2=cal-1;
        int val = n*cal2-cal2;
        k-=val;
        cout<<n*cal2+k<<endl;
    }

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
