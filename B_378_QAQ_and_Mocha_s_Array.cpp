#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
    }
    int mn = *min_element(vc.begin(),vc.end());
    for(int i=0;i<n;i++){
        if(vc[i]%mn==0) vc[i]=INT_MAX;
    }
    int mn2 = *min_element(vc.begin(),vc.end());
    for(int i=0;i<n;i++){
        if(vc[i]%mn2==0) vc[i]=INT_MAX;
    }
    for(int i=0;i<n;i++) if(vc[i]!=INT_MAX){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
