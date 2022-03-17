#include <iostream>
#include <cmath>
using namespace std;

const double E = 1e-5;

bool isPrime(int x) {
    if (x == 2) return true;
    if ((x & 1) == 0) return false;
    double sqrt_val = sqrt(x) + 1;
    for (int i = 3; i <= sqrt_val; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int odd = 0, even = 0, prime = 0, pf = 0, lf = 0;
    int n;
    cin >> n;
    if (n <= 0) {cout << ""; return 0;}
    while (n--) {
        int x;
        cin >> x;
        if ((x & 1) == 1) odd++;
        else even++;
        if (x > 1 && isPrime(x)) prime++;

        // 平方
        if (x >= 0) {
            int sqrt_val = sqrt(x);
            if (sqrt_val - floor(sqrt_val) < E) pf++;
        }

        // 立方
        double cbrt_val = cbrt(x);
        if (cbrt_val - floor(cbrt_val) < E) lf++;
    }
    printf("%d %d %d %d %d\n", odd, even, prime, pf, lf);
    return 0;
}
