#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct Cell {
    int row;
    int col;
    vector<pair<int, int>> path;
    int count;

    Cell(int r, int c, const vector<pair<int, int>>& p, int cnt) : row(r), col(c), path(p), count(cnt) {}
};

bool isValid(int row, int col, int n) {
    return row >= 0 && row < 2 && col >= 0 && col < n;
}

bool comparePaths(const vector<pair<int, int>>& path1, const vector<pair<int, int>>& path2) {
    return lexicographical_compare(path1.begin(), path1.end(), path2.begin(), path2.end());
}

void solve() {
    int n;
    scanf("%d", &n);

    char arr[2][100000];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &arr[i][j]);
        }
    }

    queue<Cell> q;
    set<vector<pair<int, int>>, decltype(&comparePaths)> visited(comparePaths);

    q.push(Cell(0, 0, {{0, 0}}, 1));

    vector<pair<int, int>> pth;
    int cnt = 0;
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.row == 1 && current.col == n - 1) {
            if (pth.empty() || comparePaths(current.path, pth)) {
                pth = current.path;
                cnt = current.count;
            }
            continue;
        }

        if (isValid(current.row, current.col + 1, n)) {
            vector<pair<int, int>> newPath = current.path;
            newPath.push_back({current.row, current.col + 1});
            q.push(Cell(current.row, current.col + 1, newPath, current.count));
        }

        if (isValid(current.row + 1, current.col, n)) {
            vector<pair<int, int>> newPath = current.path;
            newPath.push_back({current.row + 1, current.col});
            q.push(Cell(current.row + 1, current.col, newPath, current.count));
        }
    }

    // Count all optimal paths
    int optimalCount = 0;
    q.push(Cell(0, 0, {{0, 0}}, 1));
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.row == 1 && current.col == n - 1) {
            if (current.path == pth) {
                optimalCount += current.count;
            }
            continue;
        }

        if (isValid(current.row, current.col + 1, n)) {
            vector<pair<int, int>> newPath = current.path;
            newPath.push_back({current.row, current.col + 1});
            q.push(Cell(current.row, current.col + 1, newPath, current.count));
        }

        if (isValid(current.row + 1, current.col, n)) {
            vector<pair<int, int>> newPath = current.path;
            newPath.push_back({current.row + 1, current.col});
            q.push(Cell(current.row + 1, current.col, newPath, current.count));
        }
    }

    // Print lexicographically smallest path and count of optimal paths
    for (auto& coord : pth) {
        printf("%c", arr[coord.first][coord.second]);
    }
    printf("\n%d\n", optimalCount);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
