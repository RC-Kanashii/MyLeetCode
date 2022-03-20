#include <iostream>
using namespace std;

const int M = 1005;
int mat[M][M] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int j = 0; j < n; j++){
        for (int i = n - 1; i >= 0; i--) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
