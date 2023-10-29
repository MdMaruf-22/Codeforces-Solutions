#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isPrime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    } 
    return true;
}
void solve()
{
    int n;cin>>n;
    if(n==1){
        cout<<"FastestFinger"<<endl;
        return;
    }
    if(n%2 || n==2){
        cout<<"Ashishgup"<<endl;
        return;
    }
    bool f = false;
    int div;
    for(int i=2;i*i<=n;i++){
        if(n%i==0 && i%2){
            f=true;
            div=i;
            break;
        }
        if(n%i==0){
            int k = n/i;
            if(k%2){
                f=true;break;
            }
        }
    }
    if(!f){
        cout<<"FastestFinger"<<endl;
        return;
    }
    int pr = n/2;
    if(isPrime(pr)) cout<<"FastestFinger"<<endl;
    else cout<<"Ashishgup"<<endl; 
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
