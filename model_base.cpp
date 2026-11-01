
#include <iostream>
#include <queue>
using namespace std;

const int N = 10;

int grid[N][N];
int visited[N][N] = {0};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void navigate(int sx, int sy, int gx, int gy, int n) {
    queue<pair<int, int>> q;

    q.push({sx, sy});
    visited[sx][sy] = 1;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        cout << "Agent at (" << x << ", " << y << ")\n";

        if (x == gx && y == gy) {
            cout << "Goal reached!\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < n &&
                grid[nx][ny] == 0 &&
                !visited[nx][ny]) {

                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    cout << "No path found!\n";
}

int main() {
    int n;

    cout << "Enter grid size (max 10): ";
    cin >> n;

    if (n < 1 || n > N) {
        cout << "Invalid grid size!\n";
        return 0;
    }

    cout << "Enter grid (0 = Free, 1 = Obstacle):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int sx, sy, gx, gy;

    cout << "Enter starting position (row col): ";
    cin >> sx >> sy;

    cout << "Enter goal position (row col): ";
    cin >> gx >> gy;

    if (sx < 0 || sx >= n || sy < 0 || sy >= n ||
        gx < 0 || gx >= n || gy < 0 || gy >= n) {
        cout << "Invalid position!\n";
        return 0;
    }

    if (grid[sx][sy] == 1 || grid[gx][gy] == 1) {
        cout << "Start or goal is blocked!\n";
        return 0;
    }

    cout << "\nAgent Navigation using BFS\n\n";

    navigate(sx, sy, gx, gy, n);

    return 0;
}
