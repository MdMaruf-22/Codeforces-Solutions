#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 1e12;
map<int,int> mp;
void cal(){
    int x=1;
    while(1){
        int val = x*x*x;
        if(val>mx) return;
        mp[val]++;
        x++;
    }
}
void solve()
{
    int n;cin>>n;
    if(n==1){
        cout<<"NO"<<endl;
        return;
    }
    for(auto x:mp){
        if(x.first>n) break;
        int dif = n-x.first;
        if(mp.find(dif) != mp.end() && mp[dif] > 0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    cal();
    while(t--){
        solve();
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mx = 1e12;
// set<int> cubes;

// void cal(){
//     int x = 1;
//     while(1){
//         int val = x*x*x;
//         if(val > mx) return;
//         cubes.insert(val);
//         x++;
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     if (n == 1){
//         cout << "NO" << endl;
//         return;
//     }
//     for (int x : cubes){
//         if (x > n) break;
//         int dif = n - x;
//         if (cubes.count(dif) > 0){
//             cout << "YES" << endl;
//             return;
//         }
//     }
//     cout << "NO" << endl;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     cal();
//     while (t--){
//         solve();
//     }
//     return 0;
// }
