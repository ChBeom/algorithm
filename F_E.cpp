#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, f_x, f_y, s_x, s_y;
char maze[1000][1000];
int visit[1000][1000];
int dist[1000][1000];

int x_dir[4] = { -1, 1, 0, 0 };
int y_dir[4] = { 0, 0, -1, 1 };

queue<pair<int, int> > q;

void bfs(int start_x, int start_y) {
    visit[start_x][start_y] = 1;
    q.push(make_pair(start_x, start_y));
    dist[start_x][start_y]++;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M)
                && !visit[x_new][y_new] && maze[x_new][y_new] == '-') {
                visit[x_new][y_new] = 1;
                q.push(make_pair(x_new, y_new));
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
    int Testcase = 0;
    cin >> Testcase;

    for (int i = 0; i < Testcase; i++) {
        cin >> N >> M;

        for (int i = 0; i < N; ++i) {

            string row;
            cin >> row;

            for (int j = 0; j < M; ++j) {
                maze[i][j] = row[j];
                if (maze[i][j] == 'S') {
                    s_x = i;
                    s_y = j;
                }
                else if (maze[i][j] == 'E') {
                    f_x = i;
                    f_y = j;
                }
            }
        }

        bfs(s_x, s_y);

        int a = 0, b = 0, c = 0, d = 0;
        int e[4] = { 0 };

        if (f_x == 0 && f_y != 0) {
            a = dist[0][f_y + 1];
            b = dist[0][f_y - 1];
            c = dist[1][f_y];

            e[0] = a;
            e[1] = b;
            e[2] = c;
            e[3] = d;
            sort(e, e + 4);

            for (int i = 0; i < 4; i++) {
                if (e[i] > 0) {
                    cout << e[i] << endl;
                    break;
                }
                else if (e[3] < 1) {
                    cout << -1 << endl;
                    break;
                }
            }
        }
        else if (f_y == 0 && f_x != 0) {
            a = dist[f_x][1];
            c = dist[f_x + 1][0];
            d = dist[f_x - 1][0];

            e[0] = a;
            e[1] = b;
            e[2] = c;
            e[3] = d;
            sort(e, e + 4);

            for (int i = 0; i < 4; i++) {
                if (e[i] > 0) {
                    cout << e[i] << endl;
                    break;
                }
                else if (e[3] < 1) {
                    cout << -1 << endl;
                    break;
                }
            }
        }
        else if (f_x == 0 && f_y == 0) {
            a = dist[0][1];
            c = dist[1][0];

            e[0] = a;
            e[1] = b;
            e[2] = c;
            e[3] = d;
            sort(e, e + 4);

            for (int i = 0; i < 4; i++) {
                if (e[i] > 0) {
                    cout << e[i] << endl;
                    break;
                }
                else if (e[3] < 1) {
                    cout << -1 << endl;
                    break;
                }
            }
        }
        else {
            a = dist[f_x][f_y + 1];
            b = dist[f_x][f_y - 1];
            c = dist[f_x + 1][f_y];
            d = dist[f_x - 1][f_y];

            e[0] = a;
            e[1] = b;
            e[2] = c;
            e[3] = d;
            sort(e, e + 4);

            for (int i = 0; i < 4; i++) {
                if (e[i] > 0) {
                    cout << e[i] << endl;
                    break;
                }
                else if (e[3] < 1) {
                    cout << -1 << endl;
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                maze[i][j] = 0;
                visit[i][j] = 0;
                dist[i][j] = 0;
            }
        }
    }
}