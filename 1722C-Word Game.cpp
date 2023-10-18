#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    map<string,int> mp;
    vector<vector<string>> mar;
    for(int i=0;i<3;i++){
        vector<string> st;
        for(int j=0;j<n;j++){
            string s;
            cin>>s;
            mp[s]++;
            st.push_back(s);
        }
        mar.push_back(st);
    }
    vector<int> cou(3,0);
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            if(mp[mar[i][j]]==1) cou[i]+=3;
            else if(mp[mar[i][j]]==2) cou[i]++;
        }
    }
    for(auto x:cou){
        cout<<x<<" ";
    }
    cout<<endl;

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
