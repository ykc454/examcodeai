#include <iostream>
#include <queue>
using namespace std;

const int N = 10;

int grid[N][N];
bool visited[N][N] = {false};
int parentX[N][N];
int parentY[N][N];

int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, -1, 1};

void BFS(int sx, int sy, int gx, int gy, int n){
    queue<pair<int,int>> q;

    q.push({sx, sy});
    visited[sx][sy] = true;

    parentX[sx][sy] = -1;
    parentY[sx][sy] = -1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == gx && y == gy){
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n &&
               ny >= 0 && ny < n &&
               grid[nx][ny] == 0 &&
               !visited[nx][ny]
            ){
                visited[nx][ny] = true;

                parentX[nx][ny] = x;
                parentY[nx][ny] = y;
                q.push({nx, ny});
            }
        }
    }
    if(!visited[gx][gy]){
        cout << "No path found!\n";
        return;
    }
    pair<int, int> path[N * N];
    int count = 0;
    int x = gx, y = gy;

    while(x != -1){
        path[count++] = {x, y};
        int px = parentX[x][y];
        int py = parentY[x][y];
        x = px;
        y = py;
    }
    cout << "\n Shortest path: \n";
    for(int i = count - 1; i >= 0; i--){
        cout << "(" << path[i].first
            << ", " << path[i].second << ")\n";
    }
    cout << "Total moves: " << count - 1 << endl; 
}