#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;



int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        queue<vector<int>> q;
        q.push({1, 1});
        for (char c : s) {
            if (isupper(c)) {
                if (c >= 'A' && c <= 'C') q.push({1, 2});
                if (c >= 'D' && c <= 'F') q.push({1, 3});
                if (c >= 'G' && c <= 'I') q.push({2, 1});
                if (c >= 'J' && c <= 'L') q.push({2, 2});
                if (c >= 'M' && c <= 'O') q.push({2, 3});
                if (c >= 'P' && c <= 'S') q.push({3, 1});
                if (c >= 'T' && c <= 'V') q.push({3, 2});
                if (c >= 'W' && c <= 'Z') q.push({3, 3});
            }
        }
        int ans = 0;
        while (q.size() > 1) {
            auto t1 = q.front();
//            cout << t1[0] <<t1[1] <<endl;
            q.pop();
            auto t2 = q.front();
//            cout << t2[0] <<t2[1] <<endl;
            ans += abs(t2[0] - t1[0]) + abs(t2[1] - t1[1]);
//            cout << "ans " <<ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
