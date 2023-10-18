#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10;
queue<int> q1,q2;
void bfs(){
    int cnt= 0 ;
    bool f = false;
    while(!q1.empty() && !q2.empty()){
        int val1 = q1.front();
        int val2 = q2.front();
        q1.pop();
        q2.pop();
        if(val1>val2){
            q1.push(val2);
            q1.push(val1);
        }
        else{
            q2.push(val1);
            q2.push(val2);
        }
        cnt++;
        if(cnt>N){
            f=true;
            break;
        }
    }
    if(f) cout<<-1<<endl;
    else{
        if(q1.empty()) cout<<cnt<<" "<<2<<endl;
        else cout<<cnt<<" "<<1<<endl;
    }
}
void solve()
{
    int n;cin>>n;
    int a;cin>>a;
    for(int i=0;i<a;i++){
        int val;cin>>val;
        q1.push(val);
    }
    int b;cin>>b;
    for(int i=0;i<b;i++){
        int val;cin>>val;
        q2.push(val);
    }
    bfs();
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
