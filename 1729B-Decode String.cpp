#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    unordered_set<int>st;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='0' && (i==n-1 || s[i+1]!='0')){
            st.insert(i-2);
        }
    }
    string res;
    vector<string> vc;
    for(int i=0;i<n;i++){
        if(st.count(i)==1){
            int x=10*(s[i]-'0')+(s[i+1]-'0');
            res='a'+x-1;
            vc.push_back(res);
            i+=2;
        }
        else{
            res='a'+(s[i]-'0'-1);
            vc.push_back(res);
        }
    }
    for(auto x:vc){
        cout<<x;
    }
    cout<<endl;
    vc.clear();
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
