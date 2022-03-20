//#include <iostream>
//using namespace std;
//
//const int M = 105;
//const int N = 1005;
//int pri[M] = {0};
//int val[M] = {0};
//int dp[M][N] = {0};
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        cin >> pri[i] >> val[i];
//    }
//
////    for (int i = 1; i <=m; i++)
//    for (int i = 1; i <= m; i++) {  // 种类
//        for (int j = 0; j < n; j++) {  // 经费
//            dp[i][j] = max(dp[i - 1][j - pri[k]] + val[k], dp[i - 1][j]);
//
////            for (int k = 1; k <= m; k++) {  // 买哪个
////                if (j >= pri[k]) {
////                    dp[i][j] = max(dp[i - 1][j - pri[k]] + val[k], dp[i - 1][j]);
////                }
////            }
//        }
//        cout << dp[m - 1][n - 1];
//    }
//}


#include <iostream>
using namespace std;

const int M = 105;
const int N = 1005;
int pri[M] = {0};
int val[M] = {0};
int dp[N][M] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> pri[i] >> val[i];
    }

//    for (int i = 0; )
    for (int i = 1; i <= n; i++) {  // 经费
        for (int j = 1; j <= m; j++) {  // 种类
            if (i >= pri[j]){  // 买得起
                dp[i][j] = max(dp[i - pri[j]][j - 1] + val[j], dp[i][j - 1]);
//                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
            }
            else {  // 买不起
                dp[i][j] = dp[i][j - 1];
//                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
            }

        }
    }
    cout << dp[n][m];
}
