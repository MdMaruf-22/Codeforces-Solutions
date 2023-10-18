#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll l,s;
    cin>>l>>s;
    if(l>s||((l%2==0)&&(s%2==1))) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        if(l%2==1){
            for(ll i=1;i<l;i++){
                cout<<"1 ";
                s--;
            }
            cout<<s;
        }
        else{
            for(ll i=1;i<l-1;i++){
                cout<<"1 ";
                s--;
            }
            cout<<s/2<<" "<<s/2;
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
