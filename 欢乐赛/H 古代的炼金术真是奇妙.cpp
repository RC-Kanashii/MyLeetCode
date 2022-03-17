#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    while (n >= m) {
        n = n - (m - 1) * (n / m);
    }

    cout << n;
    return 0;
}
