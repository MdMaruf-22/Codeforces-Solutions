#include<bits/stdc++.h>
using namespace std;
#define int long long
bool chk(int n) {
    while(n>=0){
        if(n%11==0){
            return true;
        }
        n-=111;
    }
    return false;
}
void solve()
{
    int n;cin>>n;
    int theorem_val = (11*111)-111-11;
    if(n>theorem_val){
        cout<<"YES"<<endl;
        return;
    }
    if(chk(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
