#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
void merge(vector<pair<int, int>> &vc, vector<int> &sums, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, int>> leftVC(n1);
    vector<pair<int, int>> rightVC(n2);
    vector<int> leftSums(n1);
    vector<int> rightSums(n2);

    for (int i = 0; i < n1; i++)
    {
        leftVC[i] = vc[left + i];
        leftSums[i] = sums[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightVC[j] = vc[mid + 1 + j];
        rightSums[j] = sums[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftSums[i] <= rightSums[j])
        {
            vc[k] = leftVC[i];
            sums[k] = leftSums[i];
            i++;
        }
        else
        {
            vc[k] = rightVC[j];
            sums[k] = rightSums[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vc[k] = leftVC[i];
        sums[k] = leftSums[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vc[k] = rightVC[j];
        sums[k] = rightSums[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int, int>> &vc, vector<int> &sums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(vc, sums, left, mid);
        mergeSort(vc, sums, mid + 1, right);
        merge(vc, sums, left, mid, right);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vc(n);
    vector<int> sum(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vc[i].first >> vc[i].second;
        sum[i] = vc[i].first + vc[i].second; 
    }
     mergeSort(vc, sum, 0, n - 1);

    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i].first << " " << vc[i].second << " ";
    }
    cout << endl;
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
