#include <iostream>
#include <string>
#include <cstring>
using namespace std;



int main() {
    int T;
    cin >> T;
    while (T--) {
        int a[150] = {0};
        memset(a, 0, sizeof(a));
        int n;
        string s;
        cin >> n;
        cin >> s;

        for (char c : s) {
            a[int(c)]++;
        }
        int i, max_val = -1, max_idx = 0;
        for (i = int('a'); i <= int('z'); i++) {
            if (a[i] > max_val) max_val = a[i], max_idx = i;
        }
        cout << char(max_idx) << endl;
    }
    return 0;
}
