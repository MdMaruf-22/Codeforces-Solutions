#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    if (b > a)
        return gcd(b, a);
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

bool cmp(pair<int,int>& p1, pair<int,int>& p2){
    return p2.second>p1.second;
}
void solve()
{
    int x;cin>>x;
    vector<pair<int,int>> divi;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(lcm(i,x/i)==x) divi.push_back({i,x/i});
        }
    }
    sort(divi.begin(),divi.end(),cmp);
    cout<<divi[0].first<<" "<<divi[0].second<<endl;
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
