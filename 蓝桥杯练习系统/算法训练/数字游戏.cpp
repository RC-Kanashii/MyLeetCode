#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int yh[15] = {0};
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//int ans[15] = {0};

void solve_yh(int n) {
    yh[1] = 1;  // 从1开始
    if (n == 1) return;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            yh[j] = yh[j] + yh[j - 1];
        }
    }
}

int main() {
    int n, sum;
    cin >> n >> sum;
    solve_yh(n);

    int ans[n] = {0};
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        cnt *= 10;
        cnt += 1;
    }

    while (cnt <= pow(10, n) - 1) {
        int cnt_t = cnt++;
        bool repeated = false;
        for (int i = 0; i < n; i++) {
            if (cnt_t % 10 == 0) {
                repeated = true;
                break;
            }
            ans[n - i - 1] = cnt_t % 10;
            cnt_t /= 10;
        }
        if (repeated) continue;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j++) {
                if (ans[i] == ans[j]) {repeated = true; break;}
            }
            if (repeated) break;
        }
        if (repeated) continue;
        int sum_t = 0;
        for (int i = 0; i < n; i++) {
            sum_t += yh[i + 1] * ans[i];
        }
        if (sum_t == sum) {
//            for (auto n : yh) cout << n; cout << endl;
            for (auto n : ans) cout << n << ' ';
            return 0;
        }
//        for (auto n : ans) cout << n;
//        cout << endl;
    }




//    for (int i = 0; i <= 10 - n; i ++) {
//        for (int j = i, k = 0; j < i + n; j++) {
//            ans[k++] = a[j];
//        }
////        for (auto n : ans) cout << n; cout << endl;
//        do{
//            int sum_t = 0;
//            for (int t = 0; t < n; t++) {
//                sum_t += yh[t + 1] * ans[t];
//            }
//            if (sum_t == sum) {
//                for (auto q : ans) cout << q <<' ';
//                return 0;
//            }
//            cout << sum_t << ": ";
//            for (auto n : ans) cout << n << ' '; cout << endl;
//            for (auto n : yh) cout << n << ' '; cout << endl;
//        }while(next_permutation(ans, ans + n));
//    }


    return 0;
}
