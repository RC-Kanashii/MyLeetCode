#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int k;
    cin >> k;
    int n, sum;  // k天所对应的最大满员区间
    n  = (sqrt(1 + 8 * k) - 1) / 2;
    for (int i = 1; i <= n; i++) sum += pow(i, 2);
    sum += (k - n * (n + 1) /2) * (n + 1);
    cout <<sum;
    return 0;
}
