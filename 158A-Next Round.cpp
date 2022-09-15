#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        ump.insert({i+1,num});
    }
    int cnt=0,mx=0;
    int pos=ump.at(k);
    for(auto &x:ump){
        if(x.second>=pos && x.second>0) mx=max(mx,x.first);
    }
    cout<<mx<<endl;
    return 0;
}
