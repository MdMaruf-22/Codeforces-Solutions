#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int color[MAXN];
int steps[MAXN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            color[i] = 0;
            steps[i] = 0;
        }
        int a, b;
        cin >> a >> b;
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        queue<int> q;
        q.push(a);
        color[a] = 1;
        q.push(b);
        color[b] = 2;
        int common_vertex = -1;
        int total_steps = 0;

        while (!q.empty() && common_vertex == -1) {
            int sz = q.size();
            total_steps++; 
            for (int i = 0; i < sz; i++) {
                int v = q.front();
                q.pop();

                for (int u : adj[v]) {
                    if (color[u] == 0) {
                        color[u] = color[v];
                        steps[u] = total_steps;
                        q.push(u);
                    } else if (color[u] != color[v]) {
                        common_vertex = u;
                        break;
                    }
                }
                if (common_vertex != -1) break;
            }
        }
        //cout<<steps[common_vertex]<<endl;
        queue<int> q2;
        vector<bool> visited(n + 1, false);
        q2.push(common_vertex);
        visited[common_vertex] = true;
        total_steps = 0;
        while (!q2.empty()) {
            int sz = q2.size();
            total_steps++;
            for (int i = 0; i < sz; i++) {
                int v = q2.front();
                q2.pop();
                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        q2.push(u);
                    } else if (u != v) {
                        total_steps++;
                    }
                }
            }
        }
        
        cout << total_steps + steps[common_vertex]<< endl;
    }
    return 0;
}
