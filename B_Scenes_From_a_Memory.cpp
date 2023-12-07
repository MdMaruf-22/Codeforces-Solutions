#include<bits/stdc++.h>
using namespace std;
#define int long long

bool prime(int n){
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
    int k;cin>>k;
    string s;cin>>s;
    map<int,int> mp;
    int flag=-1;
    bool two=false,three=false,five=false,seven=false;
    for(auto x:s){
        int val = x-'0';
        mp[val]++;
        if(val==1 || val==4 || val==6 || val==8 ||val==9) flag=val;
    }
    if(flag!=-1){
        cout<<1<<endl;
        cout<<flag<<endl;
        return;
    }
    for(auto x:mp){
        if(x.second>=2){
            cout<<2<<endl;
            cout<<x.first<<x.first<<endl;
            return;
        }
    }
    vector<string> vc;
    vc.push_back("25");vc.push_back("27");
    vc.push_back("32");vc.push_back("35");
    vc.push_back("52");vc.push_back("57");
    vc.push_back("72");vc.push_back("75");
    for(int i=0;i<vc.size();i++){
        int cnt=0;
        for(int j=0;j<k;j++){
            if(s[j]==vc[i][cnt]){
                cnt++;
                if(cnt==2){
                    cout<<2<<endl;
                    cout<<vc[i]<<endl;
                    return;
                }
            }
        }
    }
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