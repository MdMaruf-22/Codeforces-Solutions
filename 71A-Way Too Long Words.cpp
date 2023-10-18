#include<iostream>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int x=s.length();
    if(x<=10) cout<<s<<endl;
    else{
        int m=s.length()-2;
        cout<<s[0]<<m<<s[x-1]<<endl;;
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
