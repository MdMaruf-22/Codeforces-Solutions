#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pre = {
        10, 11, 100, 101, 110, 111, 1000, 1001, 1010,
        1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011,
        10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011,
        11100, 11101, 11110, 11111,100000 ,100001
};
bool chk(int n){
    if(n==1) return true;
    bool flag = false;
    for(auto x:pre){
        if(n%x==0){
            //n/=x;
            flag |= chk(n/x);
        }
    }
    return flag;
}
void solve()
{
    int n;cin>>n;
    if(n==1){
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
