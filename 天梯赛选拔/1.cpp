#include <iostream>
using namespace std;

int main() {
    long l, r;
    cin >> l >> r;
    if ((l - r + 1) % 2 == 0) cout << "SAME";
    else {
        if (l % 2 == 0) cout << "EVEN";
        else cout << "ODD";
    }
}
