#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,m=0;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int x=a+b+c;
        if(x>=2) m++;
    }
    cout<<m<<endl;
}
