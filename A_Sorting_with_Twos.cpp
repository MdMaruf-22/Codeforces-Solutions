// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main(){
// 	ll t;
// 	cin>>t;
// 	while(t--){
//     	ll n;
//     	cin>>n;
//     	vector<ll> arr(n,0);
//     	for(ll i=0;i<n;i++) cin>>arr[i];
//     	bool flag=true;
//     	ll cnt=0;
//     	for(ll i=1;i<=n;){
//         	ll val=(1<<cnt);
//         	vector<ll> v;
//         	while(i<=val && i<=n){
//             	v.push_back(arr[i-1]);
//             	i++;
//         	}
//         	for(ll j=1;j<v.size();j++){
//             	if(v[j]<v[j-1]){
//                 	flag=false;
//             	}
//         	}
//         	cnt++;
//     	}
//     	if(flag){
//         	cout<<"YES"<<endl;
//     	}
//     	else{
//         	cout<<"NO"<<endl;
//     	}
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    vector<vector<int>> sx;
    int po = 0;
    for (int i = 1, po = 0; i <= n; po++)
    {
        int val = pow(2, po);
        vector<int> fck;
        for (int j = i; j <= min(val,n); j++)
        {
            fck.push_back(vc[j - 1]);
        }
        i = val + 1;
        sx.push_back(fck);
    }
    for (auto x : sx)
    {
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i - 1] > x[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
