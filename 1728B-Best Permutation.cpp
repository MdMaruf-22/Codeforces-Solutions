#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    if(n%2==0){
        for(int i=n-2;i>=1;i--){
            cout<<i<<" ";
        }
        cout<<n-1<<" "<<n<<endl;
    }
    else if(n%3!=0){
        cout<<1<<" ";
        for(int i=3;i<=n-2;i++){
            cout<<i<<" ";
        }
        cout<<2<<" "<<n-1<<" "<<n<<endl;
    }
    else{
        for(int i=1;i<=n-2;i++){
            if(i!=3) cout<<i<<" ";
        }
        cout<<3<<" "<<n-1<<" "<<n<<endl;
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
