#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

unordered_map<string, int> mapp;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
//        cin >> s;
        getline(cin, s);
        int len = s.size();
        bool invalid = false;
        if (len < 6 || len > 12) {
            cout << "illegal length" << endl;
            invalid = true;
        } else {
            for (char c : s) {
                if (!isalpha(c)) {
                    cout << "illegal charactor" << endl;
                    invalid = true;
                }
            }
            if (invalid) continue;
            if (mapp[s]) {
                cout << "acount existed" << endl;
            } else {
                mapp[s]++;
                cout << "registration complete" << endl;
            }
        }

    }
}
