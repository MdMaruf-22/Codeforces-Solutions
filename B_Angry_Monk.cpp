#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vc(k);
    for (int i = 0; i < k; i++) {
        cin >> vc[i];
    }

    int mx = *max_element(vc.begin(), vc.end());
    int ans = 0;
    bool flag = false;
    for(int i = 0; i < k ; i++){
        if(vc[i]==mx && !flag){
            
            flag=true;
            continue;
        }
            if(vc[i] == 1) ans += 1;
            else ans += vc[i] * 2 - 1;
        }
    
    cout << ans << endl; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
