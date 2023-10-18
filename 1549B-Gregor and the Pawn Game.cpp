#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    string enemy,gregor;
    cin>>enemy>>gregor;
    int cnt=0;
    if(gregor[0]=='1'){
        if(enemy[0]=='0'){
            enemy[0]='x';
            cnt++;
        }
        else if(enemy[1]=='1'){
            enemy[1]='x';
            cnt++;
        }
        
    }
    for(int i=1;i<n;i++){
        if(gregor[i]=='1'){
            if(enemy[i-1]=='1'){
                enemy[i-1]='x';
                cnt++;
            }
            else if(enemy[i]=='0'){
                enemy[i]='0';
                cnt++;
            }
            else if(enemy[i+1]=='1'){
                enemy[i+1]='x';
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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
