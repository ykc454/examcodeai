#include <iostream>
using namespace std;

int maze[100][100];
bool visited[100][100];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, startX, startY, goalX, goalY;

bool dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;

    if (maze[x][y] == 1 || visited[x][y])
        return false;

    visited[x][y] = true;
    if (x == goalX && y == goalY) {
        cout << "(" << x << "," << y << ")";
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (dfs(x + dx[i], y + dy[i])) {
            cout << "(" << x << "," << y << ")";
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Enter maze size: ";
    cin >> n;

    cout << "Enter maze (0 = Path, 1 = Wall):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }

    cout << "Enter start position (row col): ";
    cin >> startX >> startY;

    cout << "Enter goal position (row col): ";
    cin >> goalX >> goalY;

    cout << "DFS Path (Goal to Start):\n";

    if (!dfs(startX, startY))
        cout << "No path found";

    return 0;
}