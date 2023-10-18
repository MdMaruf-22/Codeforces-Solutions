#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<string> generatePermutations(const vector<char> &characters)
{
    vector<string> permutations;
    int n = characters.size();

    if (n < 2)
        return permutations;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            string permutation;
            permutation.push_back(characters[i]);
            permutation.push_back(characters[j]);
            permutations.push_back(permutation);
        }
    }

    return permutations;
}

int main()
{
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    vector<string> permutations = generatePermutations(characters);
    int t;
    cin >> t;
    while (t--)
    {
        map<string, int> mp;
        for (auto x : permutations)
            mp[x]++;
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            string nw = s.substr(i, 2);
            if (mp[nw] == 1)
            {
                cnt++;
                mp[nw]++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
