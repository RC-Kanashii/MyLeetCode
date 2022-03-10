#include <iostream>
using namespace std;

int yh[25][25] = {0};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <=20; i++) yh[i][1] = 1;
    yh[2][2] = 1;
    for (int i = 3; i <= 20 ;i++) {
        for (int j = 2; j <= i; j++) {
            yh[i][j] = yh[i - 1][j] + yh[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n ;i++) {
        for (int j = 1; j <= i; j++) {
            cout << yh[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
