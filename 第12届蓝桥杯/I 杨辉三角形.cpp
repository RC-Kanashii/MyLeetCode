#include <iostream>
using namespace std;
typedef long long ll;

ll C(ll n, ll k) {
    ll ans = 1;
    for (int i = n; i >= n - k + 1; i--) ans *= i;
    for (int i = 2; i <= k; i++) ans /= i;
    return ans;
}

int main() {
    int N;
    cout << C(32, 16);
    cin >> N;

    return 0;
}
