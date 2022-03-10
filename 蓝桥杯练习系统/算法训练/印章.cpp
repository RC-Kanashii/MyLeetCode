#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double dp[25][25] = {0};  // dp[i][j]含义：买i次凑齐j种印章的概率

int fact(int n) {
    if (n == 1) return 1;
    else return n * fact(n - 1);
}

//int main() {
//    int n, m;
//    cin >> n >> m;
//    if (m < n) cout << 0;
//    else if (n == 1) {cout << setprecision(4) << fixed << 1; return 0;}
//    else {
//        dp[n][n] = fact(n - 1) / pow(n, n - 1);
//        for (int i = n + 1; i <= m; i++)
//            dp[n][i] = dp[n][i - 1] + dp[n][n] / pow(n, i - n);
//    }
//    cout << setprecision(4) << fixed << dp[n][m];
//    //printf("%.4lf", dp[n][m]);
//    return 0;
//}

int main() {
    int n, m;  // n种印章，买m次
    cin >> n >> m;
    double p = 1.0 / n;  // 每种印章出现的概率

    // 只有一种印章的话，不论买多少次一定都能集齐
    for (int i = 1; i < 25; i++) dp[i][1] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > i) dp[i][j] = 0;  // 如果买的次数比印章种类数还少，那一定凑不齐
            else if (j == 1) dp[i][j] = pow(p, i - 1);
            else {
                dp[i][j] = dp[i - 1][j] * j * 1.0 / n + dp[i - 1][j - 1] * 1.0 * (n - j + 1) / n;
            }
        }
    }

    printf("%.4lf", dp[m][n]);
    return 0;
}
