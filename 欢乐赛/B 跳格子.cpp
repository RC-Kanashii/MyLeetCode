#include <iostream>
using namespace std;

const int N = 105;

int dp[2][N] = {0};
int a[2][N] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }

    dp[0][0] = max(0, a[1][0]) + a[0][0];
    dp[1][0] = max(0, a[0][0]) + a[1][0];

    // 从上到下，从左到右
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < 2; i++) {
            dp[i][j] = max(dp[0][j - 1], dp[1][j - 1]) + max(0, a[1 - i][j]) + a[i][j];
        }
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]);
    return 0;
}
