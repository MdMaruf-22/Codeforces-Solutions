#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x,y;cin>>n>>x>>y;
    int dif = y-x;
    vector<int> div;
    for(int i=1;i*i<=dif;i++){
        if(dif%i) continue;
        div.push_back(dif/i);
        div.push_back(i);
    }
    sort(div.begin(),div.end());
    vector<int> ans;
    bool flower=true;
    for(auto fck:div){
        vector<int> vc;
        int k=y;
        for(int i=0;i<n;i++){
            if(k<=0) break;
            vc.push_back(k);
            k-=fck;
        }
        bool mar=true,mit=true;
        if(vc.size()==n){
            for(int i=0;i<n;i++){
                if(vc[i]==x) mar=false;
                if(vc[i]==y) mit=false;
            }
            if(!mar && !mit){
                for(auto xx:vc){
                    ans.push_back(xx);
                }
                flower=false;
                break;
            }
        }
    }
    vector<int> nw_ans;
    int nw_sex=1;
    int mx = *max_element(div.begin(),div.end());
    while(nw_sex<=mx){
        bool baal=true;
        for(auto fck:div){
            vector<int> nw_vc;
            int nw_k = nw_sex;
            for(int i=0;i<n;i++){
                nw_vc.push_back(nw_k);
                nw_k+=fck;
            }
            bool mar1=true,mit1=true;
            if(nw_vc.size()==n){
                for(int i=0;i<n;i++){
                    if(nw_vc[i]==x) mar1=false;
                    if(nw_vc[i]==y) mit1=false;
                }
                if(!mar1 && !mit1){
                    for(auto xx:nw_vc) {
                        nw_ans.push_back(xx);
                    }
                    baal=false;
                    break;
                }
            }
        }
        if(!baal) break;
        nw_sex++;
    }
    if(ans.size()>0){
        for(auto sx:ans) cout<<sx<<" ";
        cout<<endl;}
    else{
        for(auto sx:nw_ans) cout<<sx<<" ";
        cout<<endl;
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
