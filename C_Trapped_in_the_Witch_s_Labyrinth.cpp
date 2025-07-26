#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1}; // Right, Down, Left, Up
const int dy[] = {1, 0, -1, 0};
const char dir[] = {'R', 'D', 'L', 'U'};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void mark_out_of_maze(int x, int y, int n, int m, vector<string>& grid, vector<vector<bool>>& out_of_maze) {
    if (!is_valid(x, y, n, m) || out_of_maze[x][y]) return;

    out_of_maze[x][y] = true;
    char d = grid[x][y];
    int nx = x, ny = y;

    if (d == 'R') nx += dx[0], ny += dy[0];
    else if (d == 'D') nx += dx[1], ny += dy[1];
    else if (d == 'L') nx += dx[2], ny += dy[2];
    else if (d == 'U') nx += dx[3], ny += dy[3];

    if (is_valid(nx, ny, n, m)) {
        mark_out_of_maze(nx, ny, n, m, grid, out_of_maze);
    }
}

void assign_directions(int n, int m, vector<string>& grid, vector<vector<bool>>& out_of_maze) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (grid[x][y] == '?') {
                bool leads_out = false;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (is_valid(nx, ny, n, m) && out_of_maze[nx][ny]) {
                        leads_out = true;
                        grid[x][y] = dir[i];
                        break;
                    }
                }
                if (!leads_out) {
                    grid[x][y] = 'R'; // Default direction for creating loops
                }
            }
        }
    }
}

int count_loops(int n, int m, vector<string>& grid, vector<vector<bool>>& out_of_maze) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int loop_count = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (!visited[x][y] && !out_of_maze[x][y]) {
                stack<pair<int, int>> s;
                s.push({x, y});
                bool forms_loop = true;

                while (!s.empty()) {
                    //auto [cx, cy] = s.top();
                    auto cx = s.top().first;
                    auto cy = s.top().second;
                    s.pop();

                    if (!is_valid(cx, cy, n, m) || visited[cx][cy] || out_of_maze[cx][cy]) {
                        forms_loop = false;
                        continue;
                    }

                    visited[cx][cy] = true;
                    char d = grid[cx][cy];
                    int nx = cx, ny = cy;

                    if (d == 'R') nx += dx[0], ny += dy[0];
                    else if (d == 'D') nx += dx[1], ny += dy[1];
                    else if (d == 'L') nx += dx[2], ny += dy[2];
                    else if (d == 'U') nx += dx[3], ny += dy[3];

                    s.push({nx, ny});
                }

                if (forms_loop) loop_count++;
            }
        }
    }

    return loop_count;
}

int solve(int n, int m, vector<string>& grid) {
    vector<vector<bool>> out_of_maze(n, vector<bool>(m, false));

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (!out_of_maze[x][y] && grid[x][y] != '?') {
                mark_out_of_maze(x, y, n, m, grid, out_of_maze);
            }
        }
    }

    assign_directions(n, m, grid, out_of_maze);
    int total_cells = n * m;
    int exit_cells = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (out_of_maze[x][y]) exit_cells++;
        }
    }

    return total_cells - exit_cells;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        cout << solve(n, m, grid) << "\n";
    }
    return 0;
}
