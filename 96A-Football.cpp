#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int x=s.size();
    int cnt1=0,cnt2=0;
    bool flag=false;
    for(int i=0;i<x;i++){
        if(s[i]=='0') cnt1++;
        else cnt1=0;
        if(s[i]=='1') cnt2++;
        else cnt2=0;
        if(cnt1>=7 || cnt2>=7){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
