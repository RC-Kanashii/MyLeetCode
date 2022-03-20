#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int mapp[1005][1005] = {0};
int ans[1005][1005] = {0};
bool vis[1005][1005] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;

bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    cin >> N >> M;
    queue<vector<int>> q;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            mapp[i][j] = s[j] - '0';
            if (mapp[i][j] == 1) {
                q.push({i, j});  // 1入队
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto vex = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = vex[0] + dx[i];
            int ny = vex[1] + dy[i];
            if (check(nx, ny) && !vis[nx][ny]) {
                q.push({nx, ny});
                ans[nx][ny] = ans[vex[0]][vex[1]] + 1;
                vis[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

}
