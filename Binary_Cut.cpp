#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;cin>>s;
    int cnt=1;bool f=false;
    string nw = "";
    vector<string> vc;
    for(int i=0;i<s.size()-1;i++){
        nw+=s[i];
        if(s[i]=='1' && s[i+1]=='0'){
            cnt++;
            vc.push_back(nw);
            nw.clear();
            f=true;
        }
    }
    nw+=s.back();
    vc.push_back(nw);
    sort(vc.begin(),vc.end());
    cnt=0;
    for(int i=0;i<vc.size()-1;i++){
        char m = vc[i].back();
        string fck = vc[i+1];
        char n = fck[0];
        if(m>n) cnt++;
    }
    //cout<<vc.size()<<" "<<cnt<<endl;
    cout<<vc.size()+cnt<<endl;
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
