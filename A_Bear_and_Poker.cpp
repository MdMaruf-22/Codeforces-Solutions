#include<bits/stdc++.h>
using namespace std;
#define int long long
int cntGCD(int a,int b){
    if(b==0) return a;
    if(b>a) return cntGCD(b,a);
    return cntGCD(b,a%b);
}
int cntLCM(int a,int b){
    return (a*b)/cntGCD(a,b);
}
void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int gc=vc[0];
    for(int i=1;i<n;i++){
        gc =cntGCD(gc,vc[i]);
    }
    //cout<<gc<<endl;
    for(int i=0;i<n;i++){
        int val = vc[i]/gc;
        while(val%2==0) val/=2;
        while(val%3==0) val/=3;
        if(val!=1){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
