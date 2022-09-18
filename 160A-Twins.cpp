#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sum/=2;
    sort(arr,arr+n,greater<int>());
    int cnt=0,x=0;
    for(int i=0;i<n;i++){
        x+=arr[i];
        cnt++;
        if(x>sum) break;
    }
    cout<<cnt<<endl;
}
