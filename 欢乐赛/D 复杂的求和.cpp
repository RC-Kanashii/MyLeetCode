#include <iostream>
using namespace std;
typedef long long ll;

//const int N = 100005;
//ll A[N] = {0};
//ll B[N] = {0};

int main() {
    int n;
    ll as = 0, bs = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        as += t;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        bs += t;
    }
    cout << as * bs;
    return 0;
}
