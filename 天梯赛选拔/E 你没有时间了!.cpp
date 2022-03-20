#include <iostream>
using namespace std;
typedef long long ll;

const ll M = 25;
const ll N = 100000005;
ll pri[M] = {0};
ll val[M] = {0};
ll dp[M] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> pri[i] >> val[i];
    }

//    for (int i = 0; )
//    for (int i = 1; i <= n; i++) {  // 经费
//        for (int j = 1; j <= m; j++) {  // 种类
//            if (i >= pri[j]) { // 买得起
//                dp[i][j] = max(dp[i - pri[j]][j - 1] + val[j], dp[i][j - 1]);
////                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
//            } else { // 买不起
//                dp[i][j] = dp[i][j - 1];
////                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
//            }
//
//        }
//    }

    for (int i = 1; i <= n; i++) {  // 经费
        for (int j = 1; j <= m; j++) {  // 种类
            if (i >= pri[j]) { // 买得起
                dp[j] = max(dp[j - 1] + val[j], dp[j - 1]);
//                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
            } else { // 买不起
                dp[j] = dp[j - 1];
//                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
            }
        }
    }

//    for (int i = 1; i <= m; i++) {  // 种类
//        for (int j = 1; j <= n; j++) {  // 经费
//            if (j >= pri[i]) { // 买得起
//                dp[j] = max(dp[j - pri[i]] + val[i], dp[j - 1]);
////                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
//            } else { // 买不起
//                dp[j] = dp[j - 1];
////                cout << "i:" << i <<"  j:" <<j <<"  dp:" <<dp[i][j] << endl;
//            }
//        }
//    }
    cout << dp[m];
}
