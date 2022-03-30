#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(long long a, long long b) {
    return a > b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<long long> n(5);
        long long ans = 0;
        for (int i = 0; i < 5; i++) cin >> n[i];
        sort(n.begin(), n.end(), cmp);
//        for (auto c : n) cout << c << ' ';
//        cout << endl;
        while (n[3]) {
            long long d = n[3] - n[4];
            if (d == 0) d = 1;
            ans += d;
            for (int i = 0; i < 4; i++) n[i] -= d;
            sort(n.begin(), n.end(), cmp);
//            for (auto c : n) cout << c << ' ';
//            cout << endl;
        }
        cout << ans << endl;
    }
}
