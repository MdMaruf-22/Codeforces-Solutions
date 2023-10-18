#include<bits/stdc++.h>
using namespace std;



void solve()
{
    int i,j,n;
    string s;
    char tmp;
    cin>>n>>s;

    int x=s.size();
    if(n!=5) cout<<"NO\n";
    else{
        for(i=0;i<x;i++){
            for(j=i+1;j<x;j++){
                if(s[i]>s[j]) swap(s[i],s[j]);
            }
        }
        if(s=="Timru") cout<<"YES\n";
        else cout<<"NO\n";
    }
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
