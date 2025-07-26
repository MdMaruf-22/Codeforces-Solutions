#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve(){
    int n;cin>>n;
    vector<int> ratA(n),ratB(n);
    for(int i=0;i<n;i++) cin>>ratA[i];
    for(int i=0;i<n;i++) cin>>ratB[i];
    int sumA=0,sumB=0,cnt2=0,cnt1=0;
    for(int i=0;i<n;i++){
        int a=ratA[i];
        int b=ratB[i];
        if(a==0 and b==-1 || a==-1 and b==0) continue;
        else if(a==1 and b==1) cnt1++;
        else if(a==-1 and b==-1) cnt2++;
        else{
            if(a>b) sumA++;
            else if(b>a) sumB++;
        }
    }
    while(cnt2--){
        if(sumA>=sumB) sumA--;
        else sumB--;
    }
    while(cnt1--){
        if(sumA>=sumB) sumB++;
        else sumA++;
    }
    cout<<min(sumA,sumB)<<endl;
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