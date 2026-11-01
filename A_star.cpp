
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    vector<int> puzzle;
    int g, h;
    int blank;

    int f() const {
        return g + h;
    }
};

int heuristic(vector<int> a, vector<int> goal) {
    int h = 0;

    for (int i = 0; i < 9; i++) {
        if (a[i] != 0) {
            for (int j = 0; j < 9; j++) {
                if (a[i] == goal[j]) {
                    h += abs(i / 3 - j / 3)
                       + abs(i % 3 - j % 3);
                    break;
                }
            }
        }
    }

    return h;
}

struct Compare {
    bool operator()(Node a, Node b) {
        return a.f() > b.f();
    }
};

void printPuzzle(vector<int> a) {
    for (int i = 0; i < 9; i++) {
        cout << a[i] << " ";
        if (i % 3 == 2)
            cout << endl;
    }
    cout << endl;
}

void AStar(vector<int> start, vector<int> goal) {
    priority_queue<Node, vector<Node>, Compare> pq;

    int blank = find(start.begin(), start.end(), 0) - start.begin();

    pq.push({start, 0, heuristic(start, goal), blank});

    vector<vector<int>> visited;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        cout << "Current State (g = " << cur.g
        << ", h = " << cur.h
        << ", f = " << cur.f() << "):\n";

        printPuzzle(cur.puzzle);
        if (cur.puzzle == goal) {
            cout << "Goal reached!\n";
            printPuzzle(cur.puzzle);
            cout << "Total moves: " << cur.g << endl;
            return;
        }

        if (find(visited.begin(), visited.end(), cur.puzzle)
            != visited.end())
            continue;

        visited.push_back(cur.puzzle);

        int x = cur.blank / 3;
        int y = cur.blank % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                vector<int> next = cur.puzzle;

                swap(next[x * 3 + y], next[nx * 3 + ny]);

                if (find(visited.begin(), visited.end(), next)
                    == visited.end()) {
                    int h = heuristic(next, goal);
                    pq.push({next, cur.g + 1, h, nx * 3 + ny});
                }
            }
        }
    }

    cout << "No solution found!\n";
}

int main() {
    vector<int> start(9), goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    cout << "Enter initial puzzle (use 0 for blank):\n";
    for (int i = 0; i < 9; i++)
        cin >> start[i];

    cout << "\nInitial Puzzle:\n";
    printPuzzle(start);

    AStar(start, goal);

    return 0;
}
