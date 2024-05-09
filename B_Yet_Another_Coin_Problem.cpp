#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> pre = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 4};
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    if(n<=15){
        cout<<pre[n]<<endl;
        continue;
    }
    int div = n%15;
    int val = n/15;
    int sum = val+pre[div];
    val-=1;
    div = n - 15*val;
    int sum2= val+pre[div];
    cout<<min(sum,sum2)<<endl;
    }
}
