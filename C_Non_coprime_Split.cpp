#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int l,r;cin>>l>>r;
    if(r<=3){
        cout<<-1<<endl;
        return;
    }
    else{
        if(r>l){
            int ans=l;
            while(l<=r){
                if(l%2==0) break;
                l++;
            }
            if(l==2) l+=2;
            cout<<l/2<<" "<<l/2<<endl; 
        }
        else{
            int cnt=-1;
            for(int i=2;i*i<=l;i++){
                if(l%i==0){
                    cnt=i;
                    break;
                }
            }
            if(cnt==-1){
                cout<<-1<<endl;
                return;
            }
            cout<<cnt<<" "<<l-cnt<<endl;
        }
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
