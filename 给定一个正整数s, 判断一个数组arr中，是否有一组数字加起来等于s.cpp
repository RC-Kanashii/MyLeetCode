#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {3, 34, 4, 12, 5, 2};

bool rec_subset(vector<int>& arr, int i, int s) {
    if (s == 0) return true;
    else if (i == 0) return arr[i] == s;
    else if (arr[i] > s) return rec_subset(arr, i - 1, s);
    else {
        return rec_subset(arr, i - 1, s - arr[i]) || rec_subset(arr, i - 1, s);
    }
}

bool dp_subset(vector<int>& arr, int i, int s) {
    // 初始化
    int len = arr.size();
    bool dp[len][s + 1];
    for (int i = 0; i < s + 1; i++) dp[0][i] = false;
    dp[0][arr[0]] = true;  // 第一行除了dp[0][arr[0]]其他都是false
    for (int i = 0; i < len; i++) dp[i][0] = true;  // 当s=0时，不论arr情况如何都一定是true

    for (int i = 1; i < len; i++) {
        for (int j = 1; j < s + 1; j++) {
            if (arr[i] > j) dp[i][j] = dp[i - 1][j];  // 如果arr[i] > j，那么一定不能选arr[i]，否则总值就超过了j
            else dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];  // 前者是选arr[i]的情况，后者是不选的情况，只要有一个成立就可以
        }
    }

    return dp[i][s];
}

int main() {
    int s;
    cin >> s;
    cout << rec_subset(arr, arr.size() - 1, s) << endl;
    cout << dp_subset(arr, arr.size() - 1, s);
    return 0;
}
