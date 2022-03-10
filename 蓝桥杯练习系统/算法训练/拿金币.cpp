#include <iostream>
using namespace std;

const int N = 1005;
int mat[N][N] = {0};
int dp[N][N] = {0};

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mat[i][j];
        }
    }

    cout << dp[n][n];
    return 0;
}
//loving cy
