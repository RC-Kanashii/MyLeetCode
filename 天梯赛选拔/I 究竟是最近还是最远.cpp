#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s += t;
    }

    int maxx = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j] != s[i]) {
//                cout <<"ne: "<<s[i] <<s[j] <<endl;
                continue;
            }
//            cout <<"equal: "<<s[i] <<s[j] <<endl;
            string tmp = s.substr(i, j - i + 1);
            int cnt = count(tmp.begin(), tmp.end(), s[i]);
//            cout << "str: " << tmp << "cnt: " << cnt <<endl;
            if (cnt <= 3) maxx = max(maxx, j - i);
        }
//        cout << "i: " << i << endl;
    }
    cout << maxx;
}
