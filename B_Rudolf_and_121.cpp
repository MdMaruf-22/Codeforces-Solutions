#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    bool flag = true;
    for (int i = 0; i < n - 2; i++) {
        if (vc[i] < 0) {
            flag = false;
        }
        int cnt = vc[i];
        vc[i] -= cnt;
        vc[i + 1] -= 2 * cnt;
        vc[i + 2] -= cnt;
    }
    if(!flag){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n-1;i++){
        if(vc[i]!=vc[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
