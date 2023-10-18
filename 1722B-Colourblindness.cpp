#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,i;
    string a,b;
    cin>>n>>a>>b;

    for(i=0;i<a.size();i++){
        if(a[i]=='G') a[i]='B';
    }
    for(i=0;i<a.size();i++){
        if(b[i]=='G') b[i]='B';
    }

    if(a==b) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
  return 0;
}
