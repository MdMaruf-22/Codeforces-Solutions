#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int x;
    cin >> x;
    vector<int> vc;
    while (x > 0)
    {
        if (x % 2 == 1)
        {
            if ((x / 2) % 2 == 1 && x > 1)
            {
                vc.push_back(-1);
                x = (x / 2) + 1;
            }
            else
            {
                vc.push_back(1);
                x = x / 2;
            }
        }
        else
        {
            vc.push_back(0);
            x = x / 2;
        }
    }

    cout << vc.size() << endl;
    for (int i = 0; i < vc.size(); i++)
        cout << vc[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
